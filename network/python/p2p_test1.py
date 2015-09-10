import socket
import threading
import sys
import time

adresse_cible = ""

def ManageClient( conn ):
    conn.send(b"Welcome to my server, type something and hit enter\n")
    while True:
        data = conn.recv(1024)
        reply = b"Ok..." + data
        if not data:
            break
        print( str(data))
        conn.sendall( reply )
    conn.close()

def CreateServer():
    server = socket.socket( socket.AF_INET , socket.SOCK_STREAM )
    host = ''
    port = 8888
    
    try:
        server.bind( (host, port ))
    except socket.error:
        print("Serveur : Bind failed")
        sys.exit
    
    print("Serveur : Socket binding complete")
    server.listen(5)
    
    while 1:
        conn, addr = server.accept()
        print("Serveur : Connected with " + addr[0] + " : " + str( addr[1] ) )
        t = threading.Thread( target = ManageClient , args= ( conn, ) )
        t.start()
        t.join()

    server.close()

    

def Client():
    s_client = socket.socket( socket.AF_INET , socket.SOCK_STREAM )
    host = adresse_cible
    port = 8889

    try:
        s_client.connect( (host , port ))
    except:
        print("Client : Failed to connect")
        sys.exit
    
    time.sleep( 3)
    message = input("Client : Enter message to send")

    try:
        s_client.sendall( message.decode() )
    except:
        print("Client : Failed sending")

    reply = s_client.recv( 4096 )
    print( reply )
    s_client.close()

if __name__ == "__main__":
    t_server = threading.Thread( target = CreateServer  )
    t_client = threading.Thread( target = Client )
    t_server.start()
    t_client.start()
    t_client.join()
    t_server.join()


