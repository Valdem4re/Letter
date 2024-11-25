cmake_minimum_required(VERSION 3.30)

project(Letter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Network)
add_subdirectory(Request)
add_subdirectory(Database)
add_subdirectory(Crypto)
add_subdirectory(Utils)
add_subdirectory(Gui)


add_executable(Letter main.cpp)

target_link_libraries(Letter PRIVATE NetworkManager)