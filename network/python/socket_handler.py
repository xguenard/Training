import socket
import sys
import threading

host = ''
port = 8888


s = socket.socket( socket.AF_INET , socket.SOCK_STREAM )
print("Socket created")


try:
    s.bind(( host, port ))
except:
    print("bind failed")
    sys.exit()
print( "Socket bind complete")

s.listen(10)
print("Socket now listening")


#function for handling connections. This will be used to create threads
def clientthead( conn):
   conn.send(b"Welcome to the server, typw something and hit enter \n")
   while True:
       data = conn.recv(1024)
       reply = b"OK..." + data
       if not data:
           break
       conn.sendall(reply)
   conn.close()

while 1:
    conn, addr = s.accept()
    print( "Connected with " + addr[0] + " : " + str(addr[1] ))
    threading._start_new_thread(clientthead, (conn,))
s.close()
