//
// Created by richa on 2/24/2024.
//

#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include "PacketSender.h"
#include <iostream>
#include <sstream>

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

    // Enable broadcast option on the socket
    BOOL broadcast = TRUE;
    if (setsockopt(udpsocket, SOL_SOCKET, SO_BROADCAST, reinterpret_cast<char*>(&broadcast),
        sizeof(broadcast)) == SOCKET_ERROR) {
        closesocket(udpsocket);
        WSACleanup();
        std::cerr << "Error setting socket option";
        return false;
    }

    // Construct sockaddr_in structure for broadcast address
    sockaddr_in destAddr;
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(9);
    destAddr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

    // Construct magic packet
    std::ostringstream packetStream;
    // Add 6 byte preamble
    packetStream << std::string(6, '\xFF');
    // Repeat MAC address 16 times
    for (int i = 0; i < 16; i++) {
        std::istringstream macStream(macAddress);
        unsigned int macByte;
        while (macStream >> std::hex >> macByte) {
            packetStream << static_cast<unsigned char>(macByte);
            if (macStream.peek() == ':') macStream.ignore();
        }
    }
    std::string magicPacket = packetStream.str();

    // Send magic packet
    int bytesSent = sendto(udpsocket, magicPacket.c_str(), magicPacket.size(), 0,
        reinterpret_cast<sockaddr*>(&destAddr), sizeof(destAddr));
    if (bytesSent == SOCKET_ERROR) {
        closesocket((udpsocket));
        WSACleanup();
        std::cerr << 'Error sending magic packet';
        return false;
    }

    closesocket(udpsocket);
    WSACleanup();

    return true; // Packet sent successfully
}

