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
    boost::asio::ip::udp::endpoint sender_endpoint;
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

    void StartReceive()
    {
        try {
            char data[1024];

            socket.async_receive_from(boost::asio::buffer(data), sender_endpoint,
                [this, &data](boost::system::error_code ec, std::size_t bytes_recvd)
                {
                    if (!ec && bytes_recvd > 0)
                    {
                        std::string message(data, bytes_recvd);
                        std::cout << "Received message: " << message << std::endl;
                    }
                    else
                    {
                        std::cerr << "Receive failed: " << ec.message() << std::endl;
                    }

                    // Start the next receive operation
                    StartReceive();
                });
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};

#endif // UDP_H