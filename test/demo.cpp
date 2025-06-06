#include "deviceInformation.h"

#include <string>
#include <iostream>
#include <unordered_map>

int main()
{
    std::string username = "admin";
    std::string password = "Beta2025.";
    std::string hostname = "http://192.168.1.90/onvif/device_service";
    DeviceInformation deviceInfo(username, password, hostname);
    std::unordered_map<std::string, std::string> info = deviceInfo.getDeviceInformation();
    for(const auto& pair : info) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}