#ifndef UDP_H
#define UDP_H

#include <boost/asio.hpp>
#include <iostream>
#include <string>


struct UDPServer
{   
    void Connect(std::string ip, int port);
    void Send(std::string message);
    boost::asio::io_service io_service;
    boost::asio::ip::udp::resolver resolver;
    boost::asio::ip::udp::endpoint receiver_endpoint;
    boost::asio::ip::udp::socket socket;
};


#endif // UDP_H
