#ifndef WIFI_H
#define WIFI_H

#include "../peripheral/network_common.h"
#include "../peripheral/uart.h"

#include <memory>
#include <string>
#include <vector>

enum class EncryptionProtocol {
    NONE,
    WEP,
    WPA,
    WPA2,
    AUTO,
};

class Wifi {
public:
    Wifi(GPIO_no tx, GPIO_no rx)
    {
        _uart = std::make_unique<Uart>(tx, rx, 115200);
        // something more
    }
    Wifi(const Wifi&) = delete; // copy constructor is deleted

    void connect(std::string ssid, std::string pass, EncryptionProtocol protocol = EncryptionProtocol::AUTO);
    void disconnect();

    bool is_connected();
    ipv4_t get_ipv4();
    ipv6_t get_ipv6();

    void add_tcp_connection(TCP&);
    void remove_tcp_connection(TCP&);

    void add_udp_connection(UDP&);
    void remove_udp_connection(UDP&);

    void add_http_connection(HTTPRequest&);
    void remove_http_connection(HTTPRequest&);

private:
    std::unique_ptr<Uart> _uart;
    std::unique_ptr<std::vector<TCP>> _tcps;
    std::unique_ptr<std::vector<UDP>> _udps;
    std::unique_ptr<std::vector<HTTPRequest>> _https;
    ipv4_t _ipv4;
    ipv6_t _ipv6;
};

#endif