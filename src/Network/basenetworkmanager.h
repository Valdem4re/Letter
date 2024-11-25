#ifndef BASE_NETWORK_MANAGER_H
#define BASE_NETWORK_MANAGER_H

#include <string>

class BaseNetworkManager {
    public:
    virtual ~BaseNetworkManager() = default;
    virtual void start() = 0;
    virtual void sendMessage(const std::string& clinetId, const std::string& msg) = 0;
};

#endif