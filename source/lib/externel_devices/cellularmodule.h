#ifndef CELLULARMODULE_H
#define CELLULARMODULE_H

#include "../peripheral/network_common.h"
#include "../peripheral/uart.h"

#include <memory>
#include <string>
#include <vector>

class CellularModule {
public:
    CellularModule(GPIO_no tx, GPIO_no rx)
    {
        _uart = std::make_unique<Uart>(tx, rx, 115200);
        // something more
    }
    CellularModule(const CellularModule&) = delete; // copy constructor is deleted

    void connect();
    void disconnect();

    bool is_connected();
    ipv4_t get_ipv4();
    ipv6_t get_ipv6();

private:
    std::unique_ptr<Uart> _uart;
    std::unique_ptr<std::vector<TCP>> _tcps;
    std::unique_ptr<std::vector<UDP>> _udps;
    std::unique_ptr<std::vector<HTTPRequest>> _https;
    ipv4_t _ipv4;
    ipv6_t _ipv6;
};

#endif