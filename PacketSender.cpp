//
// Created by richa on 2/24/2024.
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include "PacketSender.h"
#include <iostream>

#pragma comment(lib, "ws2_32.lib")

PacketSender::PacketSender() = default;

PacketSender::~PacketSender() = default;

bool PacketSender::sendMagicPacket(const std::string &macAddress) {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2,2), &wsaData) != 0) {
        std::cerr << "Error initializing Winsock\n";
        return false;
    }

    // Create UDP socket
    SOCKET udpsocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (udpsocket == INVALID_SOCKET) {
        WSACleanup();
        std::cerr << "Error creating socket\n";
        return false;
    }

    // Construct sockaddr_in structure for broadcast address
    sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(9);
    dest_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

}

