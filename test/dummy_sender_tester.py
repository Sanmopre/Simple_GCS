import time
import socket
import drone_data_pb2

def send_drone_data(address, port):
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # Initialize the sums
    altitude_sum = speed_sum = vertical_speed_sum = latitude_sum = longitude_sum = 0
    fuel_sum = temperature_engine_1_sum = temperature_engine_2_sum = rpm_engine_1_sum = rpm_engine_2_sum = 0

    try:
        while True:
            # Create a new DroneData message
            drone_data = drone_data_pb2.DroneData()

            # Set the fields of the message
            drone_data.altitude = 100 + altitude_sum
            drone_data.speed = 20.5 + speed_sum
            drone_data.vertical_speed = 10.2 + vertical_speed_sum
            drone_data.latitude = 37.421998 + latitude_sum
            drone_data.longitude = -122.084 + longitude_sum
            drone_data.fuel = 75.5 + fuel_sum
            drone_data.temperature_engine_1 = 85.6 + temperature_engine_1_sum
            drone_data.temperature_engine_2 = 95.7 + temperature_engine_2_sum
            drone_data.rpm_engine_1 = 2000 + rpm_engine_1_sum
            drone_data.rpm_engine_2 = 3000 + rpm_engine_2_sum

            # Increment the sums
            altitude_sum += 1
            speed_sum += 1
            vertical_speed_sum += 1
            latitude_sum += 1
            longitude_sum += 1
            fuel_sum += 1
            temperature_engine_1_sum += 1
            temperature_engine_2_sum += 1
            rpm_engine_1_sum += 1
            rpm_engine_2_sum += 1

            # Serialize the message to a string
            serialized_message = drone_data.SerializeToString()

            # Send the message
            sock.sendto(serialized_message, (address, port))

            # Delay between messages
            time.sleep(0.1)

    except KeyboardInterrupt:
        # Close the socket when the script is interrupted
        sock.close()

# Use the function
send_drone_data("192.168.1.110", 9124)