from socket import * 
# Create a server socket, bind it to a port and start listening 
serverSocket = socket(AF_INET, SOCK_STREAM) 
serverHost = 'localhost'
serverPort = 1235
serverSocket.bind((serverHost, serverPort))
serverSocket.listen(1)

while 1:
    print('The server is ready to receive.......') 
    connectionSocket, addr = serverSocket.accept() 
    message = connectionSocket.recv(4096).decode() 
    print(message)
    # Extract the filename from the given message 
    filename = message.split()[1]
    fileExist = "false"
    filetouse = filename
    try:
        # Check wether the file exist in the cache
        f = open(filetouse[0:], "r")
        outputdata = f.readlines()
        fileExist = "true"
        connectionSocket.send("Requested file found in cache".encode())
        # ProxyServer finds a cache hit and generates a response message connectionSocket.send("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n".encode()) connectionSocket.send('Read from cache\n'.encode())
        for i in range(0, len(outputdata)): 
            connectionSocket.send(outputdata[i].encode()) 
    # Error handling for file not found in cache
    except IOError:
        if fileExist == "false":
            connectionSocket.send("Requested file NOT found in cache, perform GET to server for file\n".encode())
            # Create a socket on the proxyserver
            c = socket(AF_INET, SOCK_STREAM) 
            hostn = "http://" + filetouse[0:] 
            connectionSocket.send(hostn.encode()) 
            try:
                # Connect to the socket to port 80
                c.connect((hostn, 80))
                # Create a temporary file on this socket and ask port 80 for the file requested by the client
                fileobj = c.makefile('r', 0)
                fileobj.write("GET " + filename + " HTTP/1.1\n\n")
                # Read the response into buffer
                buff = fileobj.readlines()
                # Create a new file in the cache for the requested file.
                # Also send the response in the buffer to client socket and the corresponding file in the cache
                tmpFile = open("./" + filename,"wb")

                for line in buff:
                    tmpFile.write(line)
                    connectionSocket.send(line.encode())
            except:
                connectionSocket.send("Illegal request".encode())
        else:
            # HTTP response message for file not found 
            connectionSocket.send("HTTP/1.1 404 Not Found\r\nContent-Type:text/html\r\n\r\n".encode())
# Close the client and the server sockets
connectionSocket.close()