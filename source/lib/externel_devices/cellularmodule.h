#ifndef CELLULARMODULE_H
#define CELLULARMODULE_H

#include "../peripheral/network_common.h"
#include "../peripheral/uart.h"

#include <memory>
#include <string>
#include <vector>

/**
 * @brief 4G module management class
 */
class CellularModule {
public:
    /**
     * @brief Constructor of 4G module class
     * @param tx tx pin of module
     * @param rx rx pin of module
     */
    CellularModule(GPIO_no tx, GPIO_no rx)
    {
        _uart = std::make_unique<Uart>(tx, rx, 115200);
        // something more
    }
    CellularModule(const CellularModule&) = delete; // copy constructor is deleted

    /**
     * @brief Connect a network over 4G
     */
    void connect();

    /**
     * @brief Disonnect from network
     */
    void disconnect();

    /**
     * @brief Write a buffer for selected pin
     * @return true if it's connected else return false
     */
    bool is_connected();

    /**
     * @brief Get current IPv4
     * @return IPv4
     */
    ipv4_t get_ipv4();

    /**
     * @brief Get current IPv6
     * @return IPv6
     */
    ipv6_t get_ipv6();

    /**
     * @brief Add TCP connection
     * @param TCP TCP object
     */
    void add_tcp_connection(TCP&);

    /**
     * @brief Remove TCP connection
     * @param TCP TCP object
     */
    void remove_tcp_connection(TCP&);

    /**
     * @brief Add UDP connection
     * @param UDP UDP object
     */
    void add_udp_connection(UDP&);

    /**
     * @brief Remove UDP connection
     * @param UDP TCP object
     */
    void remove_udp_connection(UDP&);

    /**
     * @brief Add HTTP connection
     * @param HTTPRequest HTTPRequest object
     */
    void add_http_connection(HTTPRequest&);

    /**
     * @brief Remove HTTP connection
     * @param HTTPRequest HTTPRequest object
     */
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