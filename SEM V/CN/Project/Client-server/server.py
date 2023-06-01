from pydoc import cli
import socket
import os
from _thread import *

ServerSideSocket = socket.socket()
host = '127.0.0.1'
port = 5008
ThreadCount = 0
clientList = set()

try:
    ServerSideSocket.bind((host, port))
except socket.error as e:
    print(str(e))

print('Waiting for clients...')
ServerSideSocket.listen(5)

# function to make a client connection thread
def multi_threaded_client(connection):
    msg_list = []

    connection.send(str.encode('Connected. Now, set a name ->'))
    data = connection.recv(2048)
    cname = data.decode('utf-8')

    while cname in clientList :
        connection.send(str.encode('Name already taken!! Try another.'))
        data = connection.recv(2048)
        cname = data.decode('utf-8')

    connection.send(str.encode('OK'))
    
    print("Connected to " + cname + ". (Total threads : " + str(ThreadCount) + ")")
    clientList.add(cname)
    msg_list.append(cname + " : ")

    while not quit(data.decode('utf-8')):
        data = connection.recv(2048)
        if not data:
            break
        print(cname + ' : ' + data.decode('utf-8'))

        if get_all_msg(data.decode('utf-8')):
            #get all msgs
            for m in msg_list:
                connection.send(str.encode(m))
                print(m)
            connection.send(str.encode('Quit'))
            print('All messages sent to ' + cname + '!!')
        else:
            msg_list.append(data.decode('utf-8') + " | ")
    
    drop_connection(connection)
    print(cname + " quit.")

def quit(input):
    if input.lower() == 'quit':
        return True
    return False

def get_all_msg(input):
    if input.lower() == 'get':
        return True
    return False

def start_new():
    global Client, address
    global ThreadCount
    Client, address = ServerSideSocket.accept()
    start_new_thread(multi_threaded_client, (Client, ))
    ThreadCount += 1

def drop_connection(connection):
    global ThreadCount
    ThreadCount -= 1
    connection.close()
    print("Total threads : " + str(ThreadCount))

while True:
    start_new()
ServerSideSocket.close()