//
// Created by richa on 2/25/2024.
//

#include "UI.h"

#include <iostream>
#include <string>
#include <regex>

UI::UI() = default;
UI::~UI() = default;


std::string UI::getMacAddress() {
    std::string macAddress;
    std::regex macRegex("^([0-9A-Fa-f]{2}:){5}([0-9A-Fa-f]{2})$");

    std::cout << "Welcome to the Wake app! Please enter the MAC address of the device you would like to wake:\n";
    std::cin >> macAddress;

    while (!std::regex_match(macAddress.c_str(), macRegex)) {
        std::cout << "Invalid MAC address. Please enter again:\n";
        std::cin >> macAddress;
    }

    return macAddress;
}
