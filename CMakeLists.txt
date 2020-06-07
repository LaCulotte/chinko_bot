cmake_minimum_required(VERSION 3.0)

project(chinko_bot)

add_subdirectory(std_bot)

set(CMAKE_BUILD_TYPE Debug)

set(SRCS
    chinko_bot/messages/UnknownDofusMessage.cpp
    main.cpp
)

add_executable(chinko_bot ${SRCS})

target_include_directories(chinko_bot PUBLIC ./chinko_bot/messages)
target_include_directories(chinko_bot PUBLIC ./chinko_bot/connections)

target_link_libraries(chinko_bot std_bot)

set_property(TARGET chinko_bot PROPERTY CXX_STANDARD 20)