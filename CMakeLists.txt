cmake_minimum_required(VERSION 3.0)

project(chinko_bot)

add_subdirectory(std_bot)

set(CMAKE_BUILD_TYPE Debug)

set(SRCS
    base64/base64.cpp
    chinko_bot/types/connection/authentification/GameServerInfo.cpp
    chinko_bot/messages/UnknownDofusMessage.cpp
    chinko_bot/messages/DofusMessageTypeHandler.cpp
    chinko_bot/messages/connection/authentification/HelloConnectMessage.cpp
    chinko_bot/messages/connection/authentification/ProtocolRequiredMessage.cpp
    chinko_bot/messages/connection/authentification/IdentificationMessage.cpp
    chinko_bot/messages/connection/authentification/IdentificationSuccessMessage.cpp
    chinko_bot/messages/connection/authentification/ClientKeyMessage.cpp
    chinko_bot/messages/connection/authentification/LoginQueueStatusMessage.cpp
    chinko_bot/messages/connection/authentification/SelectedServerDataMessage.cpp
    chinko_bot/messages/connection/authentification/SelectedServerDataExtendedMessage.cpp
    chinko_bot/connections/DofusClientConnection.cpp
    chinko_bot/units/dofusBotUnit/frames/connection/AuthentificationFrame.cpp
    chinko_bot/units/dofusBotUnit/frames/connection/GameServerConnectionFrame.cpp
    chinko_bot/managers/connection/AuthentificationManager.cpp
    main.cpp
)

add_executable(chinko_bot ${SRCS})

target_include_directories(chinko_bot PUBLIC ./base64)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/types/connection/authentification)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/connections)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/managers/connection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages/connection/authentification)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/frames/connection)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/units/dofusBotUnit/messages)


target_link_libraries(chinko_bot pthread)
target_link_libraries(chinko_bot stdc++fs)
target_link_libraries(chinko_bot crypto)

target_link_libraries(chinko_bot std_bot)


set_property(TARGET chinko_bot PROPERTY CXX_STANDARD 20)