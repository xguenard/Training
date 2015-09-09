import socket
import sys


try:
    s = socket.socket( socket.AF_INET , socket.SOCK_DGRAM )
except socket.error:
    print( "failed to create socket")
    sys.exit()

host = 'localhost'
port = 5100

while(1):
    msg = input("Enter message to send : " )

    try:
        s.sendto(str.encode(msg), (host,port ))
        d = s.recvfrom( 1024 )
        reply = d[0]
        addr = d[1]
        print( "server reply : " + reply.decode( "utf-8") )
    except socket.error as  msg:
        print ('Error Code : ' + str(msg[0]) + ' Message ' + msg[1])
        sys.exit()
