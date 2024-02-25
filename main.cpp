#include <iostream>

#include "PacketSender.h"

int main() {
    PacketSender packetSender;

    packetSender.sendMagicPacket("00:15:5d:e9:79:70");

    std::cout << "6c:a1:00:5e:94:60" << std::endl;
    return 0;
}
