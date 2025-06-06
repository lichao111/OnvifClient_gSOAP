#pragma once

#include <iostream>
#include <string>
#include <unordered_map>

class DeviceInformation 
{
public:
    DeviceInformation(const std::string& username, const std::string& password, const std::string& hostname)
        : username(username), password(password), hostname(hostname) {}

    std::unordered_map<std::string, std::string> getDeviceInformation();

public:
    std::string username{};
    std::string password{};
    std::string hostname{};
};