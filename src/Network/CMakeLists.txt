add_library(NetworkManager
    basenetworkmanager.h
    basenetworkmanager.cpp
    AsioNetworkManager.h
    AsioNetworkManager.cpp
)

find_package(Boost REQUIRED)
target_include_directories(NetworkManager PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(NetworkManager PRIVATE Boost::boost)