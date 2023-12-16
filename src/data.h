#ifndef DATA_H
#define DATA_H

#include <string>
#include <sstream>

struct DroneData {
    int altitude;
    float speed;
    float vertical_speed;
    float latitude;
    float longitude;
    float fuel;
    float temperature_engine_1;
    float temperature_engine_2;
    int rpm_engine_1;
    int rpm_engine_2;
};

struct GCSData {
    float throttle_1;
    float throttle_2;
    float pitch;
    float roll;
    float yaw;
    int flaps;
    int target_altitude;
    int target_speed;
    int target_vertical_speed;
    int target_bank;
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
        << gcs_data.flaps << ','
        << gcs_data.target_altitude << ','
        << gcs_data.target_speed << ','
        << gcs_data.target_vertical_speed << ','
        << gcs_data.target_bank;
    message = oss.str();
}

#endif // DATA_H