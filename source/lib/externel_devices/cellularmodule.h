#ifndef CELLULARMODULE_H
#define CELLULARMODULE_H

#include "../peripheral/uart.h"

#include <iostream>
#include <memory>

struct ipv4_t {
    uint8_t addr1;
    uint8_t addr2;
    uint8_t addr3;
    uint8_t addr4;
};

struct ipv6_t {
    uint16_t addr1;
    uint16_t addr2;
    uint16_t addr3;
    uint16_t addr4;
    uint16_t addr5;
    uint16_t addr6;
    uint16_t addr7;
    uint16_t addr8;
};

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

protected:
    CellularModule();

private:
    std::unique_ptr<Uart> _uart;
    ipv4_t _ipv4;
    ipv6_t _ipv6;
};

class TCP : public CellularModule {
public:
    TCP(std::string domain, uint16_t port);
    TCP(const TCP&) = delete; // copy constructor is deleted

    void send_data(std::string data);
    std::string recieve_data();

private:
    std::string _domain;
    uint16_t _port;
};

class UDP : public CellularModule {
public:
    UDP(std::string domain, uint16_t port);
    UDP(const UDP&) = delete; // copy constructor is deleted

    void send_data(std::string data);
    std::string recieve_data();

private:
    std::string _domain;
    uint16_t _port;
};

class HTTPRequest : public CellularModule {
public:
    HTTPRequest(std::string domain, std::string data);
    HTTPRequest(const UDP&) = delete; // copy constructor is deleted

    std::string send_data(std::string data);

private:
    std::string _domain;
    std::string _data;
};

#endif