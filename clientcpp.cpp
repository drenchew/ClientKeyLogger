#include <boost/asio.hpp>
#include <iostream>

#include "logger.hpp"

using boost::asio::ip::tcp;

int main() {

	Logger logger;
    try {
        boost::asio::io_context io_context;

        tcp::resolver resolver(io_context);
        auto endpoints = resolver.resolve("127.0.0.1", "12345");
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        std::cout << "Connected to the server!" << std::endl;

        while(1) {
            /*
             stats logging the user input 
            */
			logger.log_to_server(socket);
        }
    }
    catch (std::exception& e) {
        std::cerr << "Client error: " << e.what() << std::endl;
    }

    return 0;
}
