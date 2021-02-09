import os
import time
import json
from flask import Flask, Response, request
from flask_cors import CORS, cross_origin
import paramiko


app = Flask(__name__)
app.debug = True
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'


def create_client():
    hostname = "localhost"
    username = "she393"
    password = os.getenv("PASSWORD")

    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(hostname=hostname, username=username, password=password)
    return client


def response(message):
    res = Response(json.dumps(message))
    res.status_code = 200
    res.content_type = "application/json"
    return res


@app.route("/")
@cross_origin()
def home():
    return response("OK")


@app.route("/api/tasks/", methods=["GET", "POST", "DELETE"])
@cross_origin()
def kamel_get():
    client = create_client()
    task_name = request.args.get('name')

    if request.method == "GET":
        if task_name is not None:
            # describe behavior
            stdin, stdout, stderr = client.exec_command(f"/usr/local/bin/kamel describe integration {task_name}")  # noqa
            body = stdout.read().decode("utf-8")
            return response(body)

        stdin, stdout, stderr = client.exec_command("/usr/local/bin/kamel get")  # noqa
        body = stdout.read().decode("utf-8")
        return response(body)

    if request.method == "POST":
        # get files from client
        file_name = request.form['name']
        f = request.files['file']
        content = f.read()

        # if file exists remove it
        if os.path.exists(f'/Users/she393/Documents/{file_name}'):
            os.remove(f'/Users/she393/Documents/{file_name}')

        # write file to remote
        sftp = client.open_sftp()
        f = sftp.file(f'/Users/she393/Documents/{file_name}', 'a', -1)
        f.write(content.decode('utf-8'))
        f.flush()
        sftp.close()

        # run and return output to client
        stdin, stdout, stderr = client.exec_command(f"/usr/local/bin/kamel run /Users/she393/Documents/{file_name}")  # noqa
        body = stdout.read().decode("utf-8")
        print(stderr)
        return response(body)

    if request.method == "DELETE":
        stdin, stdout, stderr = client.exec_command(f"/usr/local/bin/kamel delete {task_name}")  # noqa
        body = stdout.read().decode("utf-8")
        return response(body)


@app.route("/api/logs/tasks/", methods=["GET"])
@cross_origin()
def kamel_logs():
    task_name = request.args.get('name')
    if task_name is None:
        return response("Need to specify task name!")
    client = create_client()
    stdin, stdout, stderr = client.exec_command(f"/usr/local/bin/kamel logs {task_name}")  # noqa
    time.sleep(1)
    stdout.channel.close()
    body = stdout.read().decode("utf-8")
    return response(body)
