from socket import *

# Create socket
serSock = socket(AF_INET, SOCK_STREAM)

# Bind
serSock.bind(('localhost', 5006))

# Listen
serSock.listen(1)

pswd = "u20cs093"

# Stay active and respond
while True:
    print("Server is ready to receive password...")
    cliSock, cliAddr = serSock.accept()

    password = cliSock.recv(4096).decode()
    msg = ''
    if password != pswd :
        msg = "Wrong password!!"
        print(msg)
        cliSock.send(msg.encode())
        cliSock.close()
        break

    msg = "Hello"
    cliSock.send(msg.encode())
    msg = cliSock.recv(4096).decode()
    print("Connected.")
    print("Client : " + msg)
    cliSock.close()