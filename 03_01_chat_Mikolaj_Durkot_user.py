import socket
import threading


def receive():
    while True:
        message = client.recv(1024).decode('UTF-8')
        if message == 'NICK':
            client.send(nickname.encode('UTF-8'))
        else:
            print(message)

def write():
    while True:
        message = f'{nickname}: {input("")}'
        client.send(message.encode('UTF-8'))
        

if __name__ == "__main__":
    
    nickname = input("What is your name? Tell me: ")
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('127.0.0.17', 12345))

    receive_thread = threading.Thread(target=receive)
    receive_thread.start()
    write_thread = threading.Thread(target=write)
    write_thread.start() 