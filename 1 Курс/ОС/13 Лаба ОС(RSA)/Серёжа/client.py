from socket import *
from RSA import rsa

host = '46.72.111.113'
port = 7777
buff_size = 1024

addr = (host, port)

client_sock = socket(AF_INET, SOCK_STREAM)

client_sock.connect(addr)

e = int((client_sock.recv(buff_size)).decode('utf8'))
n = int((client_sock.recv(buff_size)).decode('utf8'))
public = e, n
while True:

    data = input('>')
    msg = data

    if not data:
        break

    data = rsa.encrypt(public, data)
    client_sock.send(str(data).encode('utf8'))
    client_sock.send(str(msg).encode('utf8'))

client_sock.close()