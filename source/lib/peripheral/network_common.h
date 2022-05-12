#ifndef SOFTWARE_COMMON_H
#define SOFTWARE_COMMON_H

#include <cstdint>
#include <string>

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

class TCP {
public:
    TCP(std::string domain, uint16_t port);
    TCP(const TCP&) = delete; // copy constructor is deleted

    void send_data(std::string data);
    std::string recieve_data();

private:
    std::string _domain;
    uint16_t _port;
};

class UDP {
public:
    UDP(std::string domain, uint16_t port);
    UDP(const UDP&) = delete; // copy constructor is deleted

    void send_data(std::string data);
    std::string recieve_data();

private:
    std::string _domain;
    uint16_t _port;
};

class HTTPRequest {
public:
    HTTPRequest(std::string domain, std::string data);
    HTTPRequest(const UDP&) = delete; // copy constructor is deleted

    std::string send_data(std::string data);

private:
    std::string _domain;
    std::string _data;
};

#endif