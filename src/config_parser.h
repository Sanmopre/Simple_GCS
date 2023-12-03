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

        this->ip = j["ip"];
        this->port = j["port"];
    }

    std::string ip;
    int port;
};

ConfigParser* config_parser;

#endif // CONFIG_PARSER_H