import socket
import threading


def receive():
    while True:
        client, address = server.accept()
        print(f'Connected with {str(address)}.')
        
        client.send('NICK'.encode('UTF-8'))
        nickname = client.recv(1024).decode('UTF-8')
        nicknames.append(nickname)
        clients.append(client)
        
        print(f'Nick: {nickname}')
        broadcast(f'{nickname} joined the chat.'.encode('UTF-8'))
        client.send('Connected to server.'.encode('UTF-8'))
        
        thread = threading.Thread(target=handle, args=(client,))
        thread.start()

def broadcast(message):
    for client in clients:
        client.send(message)
        
def handle(client):
    while True:
        message = client.recv(1024)
        broadcast(message)
        

if __name__ == "__main__":
    
    host = '127.0.0.17'
    port = 12345

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((host, port))
    server.listen()

    clients = []
    nicknames = []

    print('Server is working...\nCurrent version: pre-alpha 0.0.1')
    receive()