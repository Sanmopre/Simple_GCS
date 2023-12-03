#include "udp.h"


void UDPServer::Connect(std::string ip, int port)
{
    {
    try {
            resolver = boost::asio::ip::udp::resolver(io_service);
            receiver_endpoint = *resolver.resolve({boost::asio::ip::udp::v4(), ip, std::to_string(port)}).begin();
            socket = boost::asio::ip::udp::socket(io_service);
            socket.open(boost::asio::ip::udp::v4());
        }
        catch (std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

void UDPServer::Send(std::string message)
{
    try {
        socket.send_to(boost::asio::buffer(&message, sizeof(message)), receiver_endpoint);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}