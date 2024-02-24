cmake_minimum_required(VERSION 3.28)
project(WOL_Interface)

set(CMAKE_CXX_STANDARD 23)

add_executable(WOL_Interface main.cpp
        PacketSender.cpp
        PacketSender.h
)
