#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include "nlohmann/json.hpp"
#include <fstream>

class ConfigParser
{
public:
    ConfigParser(std::string path)
    {
        std::ifstream file(path);
        nlohmann::json j;
        file >> j;
        file.close();

        this->uav_ip = j["uav_ip"];
        this->uav_port = j["uav_port"];
        this->local_ip = j["local_ip"];
        this->local_port = j["local_port"];
        this->window_height = j["screen_height"];
        this->window_width = j["screen_width"];
        this->resizable = j["resizable_windows"];
        this->map_file = j["map_file"];
        this->map_width = j["map_size_x"];
        this->map_height = j["map_size_y"];
        this->plane_icon = j["plane_icon"];
        this->gcs_icon = j["gcs_icon"];
        this->icon_size_x = j["icon_size_x"];
        this->icon_size_y = j["icon_size_y"];
        this->video_file = j["video_file"];
    }

    std::string uav_ip;
    int uav_port;

    std::string local_ip;
    int local_port;

    int window_height;
    int window_width;
    bool resizable;

    int map_width;
    int map_height;
    std::string map_file;
    std::string plane_icon;
    std::string gcs_icon;
    int icon_size_x;
    int icon_size_y;
    std::string video_file;
};

ConfigParser* config_parser;

#endif // CONFIG_PARSER_H