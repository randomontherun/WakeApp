#include <iostream>

#include "PacketSender.h"
#include "UI.h"

int main() {
    UI ui;
    std::string macAddress = ui.getMacAddress();

    std::cout << "You entered a valid MAC address.\n";

    PacketSender packetSender;
    packetSender.sendMagicPacket(macAddress);

    std::cout << "a8:a1:59:ea:d7:63"<< std::endl;
    return 0;
}
