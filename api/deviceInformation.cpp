#include "deviceInformation.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <stdsoap2.h>
#include <unordered_map>
#include "wsseapi.h"
#include "soapDeviceBindingProxy.h"
#include "common.h"

std::unordered_map<std::string, std::string> DeviceInformation::getDeviceInformation() 
{
    std::unordered_map<std::string, std::string> deviceInfo;
    DeviceBindingProxy deviceBindingProxy;
    deviceBindingProxy.soap_endpoint = hostname.c_str();
    if (SOAP_OK != soap_wsse_add_UsernameTokenDigest(deviceBindingProxy.soap, nullptr, username.c_str(), password.c_str())) {
        std::cerr << "Error: soap_wsse_add_UsernameTokenDigest" << std::endl;
        report_error(deviceBindingProxy.soap);
        return deviceInfo;
    }

    struct soap* soap = soap_new();
    _tds__GetDeviceInformation *GetDeviceInfo = soap_new__tds__GetDeviceInformation(soap);
    _tds__GetDeviceInformationResponse *GetDeviceInformationResponse = soap_new__tds__GetDeviceInformationResponse(soap);

    if (SOAP_OK == deviceBindingProxy.GetDeviceInformation(GetDeviceInfo, *GetDeviceInformationResponse)) {
        deviceInfo["Manufacturer"] = GetDeviceInformationResponse->Manufacturer;
        deviceInfo["Model"] = GetDeviceInformationResponse->Model;
        deviceInfo["FirmwareVersion"] = GetDeviceInformationResponse->FirmwareVersion;
        deviceInfo["SerialNumber"] = GetDeviceInformationResponse->SerialNumber;
        deviceInfo["HardwareId"] = GetDeviceInformationResponse->HardwareId;
    } else {
        std::cerr <<"Error: getDeviceInformation" << std::endl;
        //report_error(deviceBindingProxy.soap);
    }

    CLEANUP_SOAP(soap);
    return deviceInfo;
}
