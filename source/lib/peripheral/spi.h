#ifndef SPI_H
#define SPI_H

#include "hardware_common.h"

#include <cstdint>

enum class Spi_mode {
    MASTER,
    SLAVE
};

class Spi {
public:
    Spi(GPIO_no miso, GPIO_no mosi, Spi_mode mode);
    Spi(Spi&) = delete; // copy constructor is deleted

    uint8_t read_byte();

    void write_byte(uint8_t command, GPIO_no select_pin);

private:
    GPIO_no _miso;
    GPIO_no _mosi;
    Spi_mode _mode;
};

#endif