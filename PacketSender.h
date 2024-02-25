//
// Created by richa on 2/24/2024.
//

#ifndef PACKETSENDER_H
#define PACKETSENDER_H
#include <string>


class PacketSender {
public:
    PacketSender();
    ~PacketSender();

    std::string macAddress;

    bool sendMagicPacket(const std::string& macAddress);
};



#endif //PACKETSENDER_H
