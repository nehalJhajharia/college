from socket import *

# Create
cliSock = socket(AF_INET, SOCK_STREAM)

# Connect
cliSock.connect(('localhost', 5006))

data = input("Enter password : ")

# Send data
cliSock.send(data.encode())

# recv data
msg = cliSock.recv(4096).decode()
if msg != "Hello" :
    cliSock.close()
    print("Server : " + msg)
else :
    print("Server : " + msg)
    data = "Hi"
    cliSock.send(data.encode())
