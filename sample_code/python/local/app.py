import json
import subprocess
from flask import Flask, Response, request
from flask_cors import CORS, cross_origin


app = Flask(__name__)
app.debug = True
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'


def response(message):
    res = Response(json.dumps(message))
    res.status_code = 200
    res.content_type = "application/json"
    return res


@app.route("/")
@cross_origin()
def home():
    return response("HOME")


@app.route("/api/kamel/get", methods=["GET"])
@cross_origin()
def kamel_get():
    stdout = subprocess.check_output("/usr/local/bin/kamel get", shell=True)
    body = stdout.decode("utf-8")
    return response(body)


@app.route("/api/kamel/logs", methods=["GET"])
@cross_origin()
def kamel_logs():
    # TODO: implement this...
    task = request.args.get('task')
    stdout = subprocess.check_output(f"/usr/local/bin/kamel log {task}", shell=True)  # noqa
    body = stdout.decode("utf-8")
    return response(body)


@app.route("/api/kamel/describe", methods=["GET"])
@cross_origin()
def kamel_describe():
    task = request.args.get('task')
    stdout = subprocess.check_output(f"/usr/local/bin/kamel describe integration {task}", shell=True)  # noqa
    body = stdout.decode("utf-8")
    return response(body)


@app.route("/api/kamel/delete", methods=["GET"])
@cross_origin()
def kamel_delete():
    task = request.args.get('task')
    stdout = subprocess.check_output(f"/usr/local/bin/kamel delete {task}", shell=True)  # noqa
    body = stdout.decode("utf-8")
    return response(body)


@app.route("/api/kamel/submit", methods=["POST"])
@cross_origin()
def kamel_submit():
    """Submit and run a Kamel integration.

    """
    # get files from client
    file_name = request.form['name']
    f = request.files['file']
    content = f.read()

    # write file to remote
    sftp = client.open_sftp()
    f = sftp.file(f'/Users/she393/Documents/{file_name}', 'a', -1)
    f.write(content.decode('utf-8'))
    f.flush()
    sftp.close()

    # run and return output to client
    stdout = subprocess.check_output(f"/usr/local/bin/kamel run /Users/she393/Documents/{file_name}", shell=True)  # noqa
    body = stdout.decode("utf-8")
    return response(body)
