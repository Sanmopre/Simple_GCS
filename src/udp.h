#ifndef UDP_H
#define UDP_H

#include <boost/asio.hpp>
#include <iostream>
#include <string>

struct UDPServer
{   
    UDPServer() : resolver(io_service), socket(io_service) {}

    boost::asio::io_service io_service;
    boost::asio::ip::udp::resolver resolver;
    boost::asio::ip::udp::endpoint receiver_endpoint;
    boost::asio::ip::udp::socket socket;

    void Connect(std::string ip, int port)
    {
        try {
            receiver_endpoint = *resolver.resolve({boost::asio::ip::udp::v4(), ip, std::to_string(port)}).begin();
            socket.open(boost::asio::ip::udp::v4());
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }

    void Send(std::string message)
    {
        try {
            socket.send_to(boost::asio::buffer(message), receiver_endpoint);
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};

#endif // UDP_H