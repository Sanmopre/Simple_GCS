import socket

def receive_udp_messages(address, port):
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # Bind the socket to the address and port
    sock.bind((address, port))

    try:
        while True:
            # Receive the message
            data, _ = sock.recvfrom(4096)
            message = data.decode()

            # Split the message into values
            values = message.split(',')

            # Parse the values
            gcs_data = {
                'throttle_1': float(values[0]),
                'throttle_2': float(values[1]),
                'pitch': float(values[2]),
                'roll': float(values[3]),
                'yaw': float(values[4]),
                'flaps': int(values[5]),
                'target_altitude': float(values[6]),
                'target_speed': float(values[7]),
                'target_vertical_speed': float(values[8]),
                'target_bank': float(values[9]),
            }

            # Print the data
            print(gcs_data)

    except KeyboardInterrupt:
        # Close the socket when the script is interrupted
        sock.close()

# Use the function
receive_udp_messages("192.168.1.110", 9124)