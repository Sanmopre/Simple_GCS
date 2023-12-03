import socket
import struct

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
server_address = ('localhost', 5000)  # Replace 5000 with your actual port number
sock.bind(server_address)

while True:
    data, address = sock.recvfrom(4096)
    print(len(data))
    if len(data) == 4:
        value = struct.unpack('f', data)[0]
        print(f"Received: {value} from {address}")
    else:
        print(f"Received data of incorrect size from {address}")