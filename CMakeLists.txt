cmake_minimum_required(VERSION 3.0)

project(chinko_bot)

add_subdirectory(std_bot)

set(CMAKE_BUILD_TYPE Debug)

set(SRCS
    chinko_bot/messages/UnknownDofusMessage.cpp
    chinko_bot/messages/DofusMessageTypeHandler.cpp
    chinko_bot/messages/connection/authentification/HelloConnectMessage.cpp
    chinko_bot/messages/connection/authentification/ProtocolRequiredMessage.cpp
    chinko_bot/connections/DofusClientConnection.cpp
    chinko_bot/units/dofusBotUnit/frames/AuthentificationFrame.cpp
    chinko_bot/managers/AuthentificationManager.cpp
    main.cpp
)

add_executable(chinko_bot ${SRCS})

target_include_directories(chinko_bot PUBLIC ./chinko_bot/connections)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/managers)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/connection/authentification)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/frames)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/messages)


target_link_libraries(chinko_bot pthread)
target_link_libraries(chinko_bot stdc++fs)

target_link_libraries(chinko_bot std_bot)


set_property(TARGET chinko_bot PROPERTY CXX_STANDARD 20)