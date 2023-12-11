import socket

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

server_address = ('139.162.254.208', 7689)
message = b'This is the message.'

try:
    # Send data
    print(f'Sending {message}')
    sent = sock.sendto(message, server_address)
finally:
    print('Closing socket')
    sock.close()