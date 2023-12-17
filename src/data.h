#ifndef DATA_H
#define DATA_H

#include <string>
#include <sstream>
#include <iostream>

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
    std::cout << message << std::endl;
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

#endif // DATA_H