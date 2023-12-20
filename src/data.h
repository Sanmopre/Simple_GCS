#ifndef DATA_H
#define DATA_H

#include <string>
#include <sstream>
#include <iostream>
#include <map>

struct DroneData {
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

enum class Flaps { LANDING, TAKEOFF, CRUISE };

struct GCSData {
    float throttle_1 = 0;
    float throttle_2 = 0;
    float pitch = 0;
    float roll = 0;
    float yaw = 0;
    Flaps flaps = Flaps::LANDING;
    int target_altitude = 0;
    int target_speed = 0;
    int target_vertical_speed = 0;
    int target_bank = 0;
};

void ParseDroneData(const std::string& message, DroneData& drone_data) {
    std::istringstream iss(message);
    std::string token;
    std::getline(iss, token, ',');
    drone_data.altitude = std::stoi(token);
    std::getline(iss, token, ',');
    drone_data.speed = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.vertical_speed = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.latitude = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.longitude = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.fuel = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.temperature_engine_1 = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.temperature_engine_2 = std::stof(token);
    std::getline(iss, token, ',');
    drone_data.rpm_engine_1 = std::stoi(token);
    std::getline(iss, token, ',');
    drone_data.rpm_engine_2 = std::stoi(token);
}

void CreateGCSData(const GCSData& gcs_data, std::string& message) {
    std::ostringstream oss;
    oss << gcs_data.throttle_1 << ','
        << gcs_data.throttle_2 << ','
        << gcs_data.pitch << ','
        << gcs_data.roll << ','
        << gcs_data.yaw << ','
        << static_cast<int>(gcs_data.flaps) << ','
        << gcs_data.target_altitude << ','
        << gcs_data.target_speed << ','
        << gcs_data.target_vertical_speed << ','
        << gcs_data.target_bank;
    message = oss.str();
}

void shift_and_add(float arr[], int size, float value) {
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