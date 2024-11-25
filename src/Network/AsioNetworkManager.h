#ifndef ASIO_NETWORK_MANAGER_H
#define ASIO_NETWORK_MANAGER_H

#include "basenetworkmanager.h"

#include <boost/asio.hpp>
#include <unordered_map>
#include <memory>
#include <iostream>

using boost::asio::ip::tcp;

class AsioNetworkManager : public BaseNetworkManager {
    public:

    AsioNetworkManager(boost::asio::io_context& io_context, unsigned short port);

    ~AsioNetworkManager() = default;

    void start() override;

    //TODO: develope more abstract entities and controllers for this
    void sendMessage(const std::string& clientID, const std::string& msg) override;

    private:

    boost::asio::io_context& io_context_;
    tcp::acceptor acceptor_;
    std::unordered_map<std::string, std::shared_ptr<tcp::socket>> clients_map_;

    //TODO: develope a class for this
    void acceptConnections();

    //TODO: also develope a class
    void handleClient(std::shared_ptr<tcp::socket> socket, const std::string& clientID);
};

#endif