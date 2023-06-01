import socket

ClientMultiSocket = socket.socket()
host = '127.0.0.1'
port = 5008
name = ''
msg_list = []
try:
    ClientMultiSocket.connect((host, port))
except socket.error as e:
    print(str(e))

res = ClientMultiSocket.recv(2048) # connected
print(res.decode('utf-8'))
while res.decode('utf-8') != 'OK':
    ClientMultiSocket.send(str.encode(input("Name : ")))
    res = ClientMultiSocket.recv(2048)
    print(res.decode('utf-8'))

def quit(input):
    if input.lower() == 'quit':
        return True
    return False

def get_all_msg(input):
    if input.lower() == 'get':
        return True
    return False

Input = ''
while not quit(Input):
    Input = input()
    ClientMultiSocket.send(str.encode(Input))

    if get_all_msg(Input):
        res = ClientMultiSocket.recv(2048)
        while not quit(res.decode('utf-8')):
            msg_list.append(res.decode('utf-8'))
            print(res.decode('utf-8'))
            res = ClientMultiSocket.recv(2048)
        print('*********************************')

ClientMultiSocket.close()