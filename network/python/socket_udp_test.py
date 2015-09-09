
import socket

host = ''
port = 5100
try:
    s = socket.socket( socket.AF_INET , socket.SOCK_DGRAM )
    print("Socket created")
except:
    print("failed to create socket.")

try:
    s.bind((host, port ))
except:
    print("didn't bind")
    sys.exit()

print( " waiting on port: " + str(port) )



while 1:
    d = s.recvfrom(1024)
    data = d[0]
    addr = d[1]

    if not data:
        break

    reply = b"OK..." + data
    s.sendto( reply , addr)
    print( "Message [ " + str(addr[0]) + " : " + str( addr[1] ) + " ] - " + data.decode("utf-8") )

s.close()



