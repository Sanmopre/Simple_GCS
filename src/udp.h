#ifndef UDP_H
#define UDP_H

#include <boost/asio.hpp>
#include <string>
#include <iostream>

class UDPServer {
public:
    UDPServer(boost::asio::io_service& io_service, const std::string& send_ip, short send_port, const std::string& recv_ip, short recv_port)
        : send_socket_(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 0)),
          recv_socket_(io_service, boost::asio::ip::udp::endpoint(boost::asio::ip::address::from_string(recv_ip), recv_port)),
          send_endpoint_(boost::asio::ip::address::from_string(send_ip), send_port) {
        start_receive();
    }

    void send(const std::string& message) {
        send_socket_.send_to(boost::asio::buffer(message), send_endpoint_);
    }

    void start_receive() {
        recv_socket_.async_receive_from(
            recv_buffer_.prepare(1024), recv_endpoint_,
            [this](boost::system::error_code ec, std::size_t bytes_transferred) {
                if (!ec) {
                    // Indicate that the received data is ready to be processed
                    recv_buffer_.commit(bytes_transferred);
                    // Convert the received data to a string
                    std::string message(boost::asio::buffer_cast<const char*>(recv_buffer_.data()), bytes_transferred);
                    // Print the message
                    message_ = message;
                    // Clear the receive buffer
                    recv_buffer_.consume(bytes_transferred);
                }
                // Start another asynchronous receive operation
                start_receive();
            });
    } 

    std::string get_message() {
        return message_;
    }


private:
    boost::asio::ip::udp::socket send_socket_;
    boost::asio::ip::udp::socket recv_socket_;
    boost::asio::ip::udp::endpoint send_endpoint_;
    boost::asio::ip::udp::endpoint recv_endpoint_;
    boost::asio::streambuf recv_buffer_;
    std::string message_;
};

#endif // UDP_H