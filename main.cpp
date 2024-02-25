#include <iostream>

#include "PacketSender.h"

int main() {
    PacketSender packetSender;

    packetSender.sendMagicPacket("a8:a1:59:ea:d7:63");

    std::cout << "6c:a1:00:5e:94:60" "00:15:5d:e9:79:70"<< std::endl;
    return 0;
}
