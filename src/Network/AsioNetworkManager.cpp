#include "AsioNetworkManager.h"

#define MAXBUFSIZE 1024

AsioNetworkManager::AsioNetworkManager(boost::asio::io_context& io_context, unsigned short port) :
io_context_(io_context), acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) 
{
    
}

void AsioNetworkManager::start() {
    acceptConnections();
}

void AsioNetworkManager::sendMessage(const std::string& clientID, const std::string& msg) {
    
}

void AsioNetworkManager::acceptConnections() {
    auto socket = std::make_shared<tcp::socket>(io_context_);
    acceptor_.async_accept(*socket, [this, socket](boost::system::error_code ec) {
        if(!ec) {
            std::string id = socket->remote_endpoint().address().to_string();
            clients_map_[id] = socket;
            std::cout << "[AsioNetworkManager] New client connected: " << id << std::endl;
            handleClient(socket, id);
        }
        acceptConnections();
    });
}

void AsioNetworkManager::handleClient(std::shared_ptr<tcp::socket> socket, const std::string& clientID) {
    auto buffer = std::make_shared<std::vector<char>>(MAXBUFSIZE);

    socket->async_read_some(boost::asio::buffer(*buffer), 
    [this, socket, clientID, buffer](boost::system::error_code ec, size_t length) {
        if(!ec) {
            std::string message(buffer->data(), length);
            std::cout << "[AsioNetworkManager] Received from: " << clientID << ": " << message << std::endl;

            //TODO: query handling...


        }
        else {
            std::cout << "[AsioNetworkManager] Client disconnected: " << clientID << " (" << ec.message() << ")" << std::endl;
            clients_map_.erase(clientID);
        }
    });
}