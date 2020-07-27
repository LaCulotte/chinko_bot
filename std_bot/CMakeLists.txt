cmake_minimum_required(VERSION 3.0)

project(std_bot)

set(CMAKE_BUILD_TYPE Debug)

set(SRCS
    logger/Logger.cpp
    dataContainers/MessageDataBuffer.cpp
    messaging/MessageInterface.cpp
    connection/NetworkConnection.cpp
    connection/PrefixNetworkConnection.cpp
    connection/ClientConnection.cpp
    connection/ServerConnection.cpp
    connection/ListeningServer.cpp
    frames/basicFrames/TimeFrame.cpp
    frames/connectionFrames/BasicConnectionUnitFrame.cpp
    units/WorkingUnit.cpp
    units/MessagingUnit.cpp
    units/ConnectionUnit.cpp
    std_include/socket_include.cpp
)

add_library(std_bot ${SRCS})

target_include_directories(std_bot PUBLIC ./std_include)
target_include_directories(std_bot PUBLIC ./dataContainers)
target_include_directories(std_bot PUBLIC ./logger)
target_include_directories(std_bot PUBLIC ./messaging)
target_include_directories(std_bot PUBLIC ./messaging/basicMessages)
target_include_directories(std_bot PUBLIC ./messaging/connectionMessages)
target_include_directories(std_bot PUBLIC ./frames)
target_include_directories(std_bot PUBLIC ./frames/basicFrames)
target_include_directories(std_bot PUBLIC ./frames/connectionFrames)
target_include_directories(std_bot PUBLIC ./connection)
target_include_directories(std_bot PUBLIC ./units)

target_link_libraries(std_bot pthread)
target_link_libraries(std_bot stdc++fs)

set_property(TARGET std_bot PROPERTY CXX_STANDARD 20)