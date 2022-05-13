#ifndef SOFTWARE_COMMON_H
#define SOFTWARE_COMMON_H

#include <cstdint>
#include <string>

/**
 * @brief IPv4 struct can hold 32bit IP
 */
struct ipv4_t {
    uint8_t addr1;
    uint8_t addr2;
    uint8_t addr3;
    uint8_t addr4;
};

/**
 * @brief IPv6 struct can hold 128bit IP
 */
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

/**
 * @brief TCP class
 */
class TCP {
public:
    /**
     * @brief Constructor of TCP class
     */
    TCP(std::string domain, uint16_t port);
    TCP(const TCP&) = delete; // copy constructor is deleted

    /**
     * @brief Send a string over TCP
     * @param data Data to send
     */
    void send_data(std::string data);

    /**
     * @brief Read a string via TCP
     * @return Read data
     */
    std::string recieve_data();

private:
    std::string _domain;
    uint16_t _port;
};

/**
 * @brief UDP class
 */
class UDP {
public:
    /**
     * @brief Constructor of UDP class
     */
    UDP(std::string domain, uint16_t port);
    UDP(const UDP&) = delete; // copy constructor is deleted

    /**
     * @brief Send a string over UDP
     * @param data Data to send
     */
    void send_data(std::string data);

    /**
     * @brief Read a string via UDP
     * @return Read data
     */
    std::string recieve_data();

private:
    std::string _domain;
    uint16_t _port;
};

/**
 * @brief HTTP Request class
 */
class HTTPRequest {
public:
    /**
     * @brief Constructor of HTTP Request class
     */
    HTTPRequest(std::string domain, std::string data);
    HTTPRequest(const UDP&) = delete; // copy constructor is deleted

    /**
     * @brief Send a string over HTTP Request with response
     * @param data Data to send
     * @return response
     */
    std::string send_data(std::string data);

private:
    std::string _domain;
    std::string _data;
};

#endif