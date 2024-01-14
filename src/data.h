#ifndef DATA_H
#define DATA_H

#include <string>
#include <sstream>
#include <iostream>
#include <map>

//Protobuf classes
#include "gcs_data.pb.h"
#include "drone_data.pb.h"

struct DroneData_Internal {
    int altitude = 0;
    float speed = 0;
    float vertical_speed = 0;
    float latitude = 0;
    float longitude = 0;
    float fuel = 0;
    float temperature_engine_1 = 0;
    float temperature_engine_2 = 0;
    int rpm_engine_1 = 0;
    int rpm_engine_2 = 0;
};

enum class Flaps_Internal { LANDING, TAKEOFF, CRUISE };
enum class Mode_Internal { AUTO, MANUAL };

struct GCSData_Internal {
    float throttle_1 = 0;
    float throttle_2 = 0;
    float pitch = 0;
    float roll = 0;
    float yaw = 0;
    Flaps_Internal flaps = Flaps_Internal::LANDING;
    Mode_Internal mode = Mode_Internal::MANUAL;
    int target_altitude = 0;
    int target_speed = 0;
    int target_vertical_speed = 0;
    int target_bank = 0;
};

void ParseDroneData(const std::string& message, DroneData_Internal& drone_data) {

    std::cout << "Recieved message: " << message << std::endl;
    DroneData drone_data_pb;
    drone_data_pb.ParseFromString(message);

    drone_data.altitude = drone_data_pb.altitude();
    drone_data.speed = drone_data_pb.speed();
    drone_data.vertical_speed = drone_data_pb.vertical_speed();
    drone_data.latitude = drone_data_pb.latitude();
    drone_data.longitude = drone_data_pb.longitude();
    drone_data.fuel = drone_data_pb.fuel();
    drone_data.temperature_engine_1 = drone_data_pb.temperature_engine_1();
    drone_data.temperature_engine_2 = drone_data_pb.temperature_engine_2();
    drone_data.rpm_engine_1 = drone_data_pb.rpm_engine_1();
    drone_data.rpm_engine_2 = drone_data_pb.rpm_engine_2();


}
void CreateGCSData(const GCSData_Internal& gcs_data, std::string& message) {

    GCSData gcs_data_pb;
    gcs_data_pb.set_throttle_1(gcs_data.throttle_1);
    gcs_data_pb.set_throttle_2(gcs_data.throttle_2);
    gcs_data_pb.set_pitch(gcs_data.pitch);
    gcs_data_pb.set_roll(gcs_data.roll);
    gcs_data_pb.set_yaw(gcs_data.yaw);
    gcs_data_pb.set_flaps(static_cast<Flaps>(gcs_data.flaps));
    gcs_data_pb.set_mode(static_cast<Mode>(gcs_data.mode));
    gcs_data_pb.set_target_altitude(gcs_data.target_altitude);
    gcs_data_pb.set_target_speed(gcs_data.target_speed);
    gcs_data_pb.set_target_vertical_speed(gcs_data.target_vertical_speed);
    gcs_data_pb.set_target_bank(gcs_data.target_bank);

    gcs_data_pb.SerializeToString(&message);
}

void shift_and_add(float arr[], int size, float value) 
{
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = value;
}


#define WARNING_MESSAGES_START 8

std::map<int, std::string> uav_messages_map {
    //CRITIAL
    {0, "LOW ENGINE 1 RPM"},
    {1, "LOW ENGINE 2 RPM"},
    {2, "HIGH ENGINE 1 RPM"},
    {3, "HIGH ENGINE 2 RPM"},
    {4, "HIGH ENGINE 1 TEMPERATURE"},
    {5, "HIGH ENGINE 2 TEMPERATURE"},
    {6, "LOW FUEL"},
    {7, "STALL"},

    //WARNING
    {8, "BAD UAV CONNECTION"},
    {9, "LESS THAN 50% FUEL"},
    {10, "LOW ALTITUDE"},
    {11, "HIGH SPEED"},
    {12, "OUT OF RANGE"}

};

#endif // DATA_H