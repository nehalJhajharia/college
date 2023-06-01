from socket import *
serverName = 'localhost'
serverPort = 1235
request=input('Enter a request: ')
clientSocket = socket(AF_INET, SOCK_STREAM) 
clientSocket.connect((serverName, serverPort)) 
clientSocket.send(request.encode()) 
returnFromSever = clientSocket.recv(4096) 
while(len(returnFromSever)>0):
    print(returnFromSever.decode()) 
    returnFromSever = clientSocket.recv(4096)
clientSocket.close()