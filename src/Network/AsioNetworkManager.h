#ifndef ASIO_NETWORK_MANAGER_H
#define ASIO_NETWORK_MANAGER_H

#include "basenetworkmanager.h"

#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class AsioNetworkManager : public BaseNetworkManager {
    public:

    AsioNetworkManager();
} 

#endif