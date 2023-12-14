import socket
import struct

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to a specific address and port
server_address = ('139.162.254.208', 5000)  # Replace 5000 with your actual port number
sock.bind(server_address)

while True:
    print('\nWaiting to receive message')
    data, address = sock.recvfrom(4096)

    print(f'Received {len(data)} bytes from {address}')
    message = data.decode('utf-8')
    print(f'Message: {message}')

    # Parse the message
    try:
        float1, float2, int1 = map(float, message.split(','))
        print(f'Parsed values: {float1}, {float2}, {int(int1)}')
    except ValueError:
        print('Could not parse message')

# Don't forget to close the socket once done
sock.close()
