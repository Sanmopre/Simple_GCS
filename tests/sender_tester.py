import socket
import time

def send_udp_messages(address, port):
    # Create a UDP socket
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    
    try:
        altitude_sum = 0
        speed_sum = 0
        vertical_speed_sum = 0
        latitude_sum = 0
        longitude_sum = 0
        fuel_sum = 0
        temperature_engine_1_sum = 0
        temperature_engine_2_sum = 0
        rpm_engine_1_sum = 0
        rpm_engine_2_sum = 0

        while True:
            altitude = 100 + altitude_sum
            speed = 20.5 + speed_sum
            vertical_speed = 10.2 + vertical_speed_sum
            latitude = 37.421998 + latitude_sum
            longitude = -122.084 + longitude_sum
            fuel = 75.5 + fuel_sum 
            temperature_engine_1 = 85.6 + temperature_engine_1_sum
            temperature_engine_2 = 95.7 + temperature_engine_2_sum
            rpm_engine_1 = 2000 + rpm_engine_1_sum
            rpm_engine_2 = 3000 + rpm_engine_2_sum

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
            

            # Format the message
            message = f"{altitude},{speed},{vertical_speed},{latitude},{longitude},{fuel},{temperature_engine_1},{temperature_engine_2},{rpm_engine_1},{rpm_engine_2}"
           
            # Send the message
            sock.sendto(message.encode(), (address, port))
           
            # Delay between messages
            time.sleep(0.1)

    except KeyboardInterrupt:
        # Close the socket when the script is interrupted
        sock.close()

# Use the function
send_udp_messages("192.168.1.119", 9123)
