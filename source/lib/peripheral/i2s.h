#ifndef I2S_H
#define I2S_H

#include "hardware_common.h"

#include <cstdint>

enum class I2s_mode {
    MASTER,
    SLAVE
};

class I2s {
public:
    I2s(GPIO_no sck, GPIO_no ws, GPIO_no sd, I2s_mode mode);
    I2s(I2s&) = delete; // copy constructor is deleted

    uint8_t read_byte();

    void write_byte(uint8_t command);

private:
    GPIO_no _sck;
    GPIO_no _ws;
    GPIO_no _sd;
    I2s_mode _mode;
};

#endif