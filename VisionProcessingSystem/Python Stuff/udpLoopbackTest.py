import socket
import struct


UDP_IP = "127.0.0.1"
UDP_PORT = 12345


sock = socket.socket(socket.AF_INET, # Internet
                     socket.SOCK_DGRAM) # UDP
sock.bind(('', UDP_PORT))


while True:
    data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
    (type, sequence, confidence, xloc, yloc, radius, distance) = struct.unpack("iIiiiid", data)
    print "received message:"
    print type
    print sequence
    print confidence
    print xloc
    print yloc
    print radius
    print distance

    # Log the packet (location and radius)

