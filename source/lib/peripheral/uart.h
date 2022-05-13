#ifndef UART_H
#define UART_H

#include "hardware_common.h"

#include <cstdint>
#include <iosfwd>

/**
 * @brief Enum class for Uart stop bit. Use BIT1 or BIT2
 */
enum class UART_stop_bit {
    BIT1,
    BIT2
};

/**
 * @brief Enum class for Uart parity bit. Use NONE, EVEN or ODD
 */
enum class UART_parity {
    NONE,
    EVEN,
    ODD
};

/**
 * @brief UART management class
 */
class Uart {
public:
    /**
     * @brief Constructor of UART class
     * @param tx TX pin for Uart
     * @param rx RX pin for Uar
     * @param baud_rate Baud rate of communucation
     * @param stop_bit Stop bit
     * @param parity Parity
     */
    Uart(GPIO_no tx, GPIO_no rx, uint32_t baud_rate, UART_stop_bit stop_bit = UART_stop_bit::BIT1, UART_parity parity = UART_parity::NONE);
    Uart(const Uart&) = delete; // copy constructor is deleted

    /**
     * @brief Get baud rate
     * @return Current baut rate
     */
    uint32_t get_baud_rate();

    /**
     * @brief Get stop bit
     * @return Current stop bit
     */
    UART_stop_bit get_stop_bit();

    /**
     * @brief Get parity
     * @return Current parity setting
     */
    UART_parity get_parity();

    /**
     * @brief Set baud rate
     * @param baud_rate Baud rate
     */
    void change_baud_rate(uint32_t baud_rate);

    /**
     * @brief Change stop bit
     * @param stop_bit Stop bit
     */
    void change_stop_bit(UART_stop_bit stop_bit);

    /**
     * @brief Change parity
     * @param parity Parity
     */
    void change_parity(UART_parity parity);

    // functions for << operator
    Uart& operator<<(bool val);
    Uart& operator<<(short val);
    Uart& operator<<(unsigned short val);
    Uart& operator<<(int val);
    Uart& operator<<(unsigned int val);
    Uart& operator<<(long val);
    Uart& operator<<(unsigned long val);
    Uart& operator<<(long long val);
    Uart& operator<<(unsigned long long val);
    Uart& operator<<(float val);
    Uart& operator<<(double val);
    Uart& operator<<(long double val);
    Uart& operator<<(void* val);
    Uart& operator<<(std::streambuf* sb);
    Uart& operator<<(Uart& (*pf)(Uart&));
    Uart& operator<<(std::ios& (*pf)(std::ios&));
    Uart& operator<<(std::ios_base& (*pf)(std::ios_base&));

    // functions for output and input streams
    friend std::ostream& operator<<(std::ostream& os, const Uart& data);
    friend std::istream& operator>>(std::istream& is, Uart& data);

private:
    GPIO_no _tx;
    GPIO_no _rx;
    uint32_t _baud_rate;
    UART_stop_bit _stop_bit;
    UART_parity _parity;
};

#endif