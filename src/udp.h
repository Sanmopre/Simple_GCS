#pragma once

#include <boost/asio.hpp>
#include <iostream>
#include <string>

void SendUDPMessage(std::string message, std::string ip, int port)
{
    try {
        boost::asio::io_service io_service;

        boost::asio::ip::udp::resolver resolver(io_service);
        boost::asio::ip::udp::endpoint receiver_endpoint = *resolver.resolve({boost::asio::ip::udp::v4(), ip, std::to_string(port)}).begin();
        boost::asio::ip::udp::socket socket(io_service);
        socket.open(boost::asio::ip::udp::v4());

        socket.send_to(boost::asio::buffer(&message, sizeof(message)), receiver_endpoint);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
