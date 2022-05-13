#ifndef SPI_H
#define SPI_H

#include "hardware_common.h"

#include <cstdint>

/**
 * @brief SPI mode struct. Use MASTER or SLAVE
 */
enum class Spi_mode {
    MASTER,
    SLAVE
};

/**
 * @brief SPI communucation protocol class
 */
class Spi {
public:
    /**
     * @brief Constructor of SPI class
     * @param miso MIOS pin
     * @param mosi MOSI pin
     * @param mode SPI working mode
     */
    Spi(GPIO_no miso, GPIO_no mosi, Spi_mode mode);
    Spi(Spi&) = delete; // copy constructor is deleted

    /**
     * @brief Read byte from I2C buffer
     * @return a byte from buffer
     */
    uint8_t read_byte();

    /**
     * @brief Write a buffer for selected pin
     * @param command Command
     * @param select_pin Selected pin
     */
    void write_byte(uint8_t command, GPIO_no select_pin);

private:
    GPIO_no _miso;
    GPIO_no _mosi;
    Spi_mode _mode;
};

#endif