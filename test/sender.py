import socket
import time

def send_udp_messages(message, address, port):
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        while True:
            # Send the message
            sock.sendto(message.encode(), (address, port))
            # Delay between messages
            time.sleep(0.1)
    except KeyboardInterrupt:
        # Close the socket when the script is interrupted
        sock.close()

# Use the function
send_udp_messages("Hello, World!", "192.168.1.119", 9123)