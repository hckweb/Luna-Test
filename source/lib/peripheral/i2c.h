#ifndef I2C_H
#define I2C_H

#include "hardware_common.h"

#include <cstdint>

enum class I2c_mode {
    MASTER,
    SLAVE
};

class I2c {
public:
    I2c(GPIO_no sda, GPIO_no scl, I2c_mode type, uint32_t speed, bool sda_pull_up, bool scl_pull_up);
    I2c(I2c&) = delete; // copy constructor is deleted

    void start();
    void stop();

    uint8_t read_byte();

    void write_byte(uint8_t command);
    void write_byte(uint8_t command, uint8_t slave_address);

private:
    GPIO_no _sda;
    GPIO_no _scl;
    I2c_mode _type;
    uint32_t _speed;
};

#endif