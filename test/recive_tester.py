import socket
import gcs_data_pb2
from google.protobuf.json_format import MessageToDict
from gpiozero import AngularServo

servo = AngularServo(18, min_pulse_width=0.0006, max_pulse_width=0.0023)

def receive_udp_messages(address, port):
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    # Bind the socket to the address and port
    sock.bind((address, port))

    try:
        while True:
            # Receive the message
            data, _ = sock.recvfrom(4096)

            # Parse the message
            gcs_data = gcs_data_pb2.GCSData()
            gcs_data.ParseFromString(data)

            # Convert the message to a dictionary and print it
            gcs_data_dict = MessageToDict(gcs_data)
            print("Received message from GCS:", gcs_data_dict)

            if 'pitch' in gcs_data_dict:
                servo.angle = gcs_data_dict['pitch']

    except KeyboardInterrupt:
        # Close the socket when the script is interrupted
        sock.close()

# Use the function
receive_udp_messages("192.168.1.145", 9124)