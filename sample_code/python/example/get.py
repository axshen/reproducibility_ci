import os
import paramiko


if __name__ == "__main__":
    hostname = "localhost"
    username = "she393"
    password = os.getenv("PASSWORD")

    client = paramiko.SSHClient()
    client.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    client.connect(hostname=hostname, username=username, password=password)

    stdin, stdout, stderr = client.exec_command("/usr/local/bin/kamel get")  # noqa
    print(stdout.read().decode('utf-8').strip("\n"))
