#ifndef I2S_H
#define I2S_H

#include "hardware_common.h"

#include <cstdint>

/**
 * @brief I2S mode struct. Use MASTER or SLAVE
 */
enum class I2s_mode {
    MASTER,
    SLAVE
};

/**
 * @brief I2S class
 */
class I2s {
public:
    /**
     * @brief Constructor of I2S class
     * @param sck SCK pin
     * @param ws WS pin
     * @param sd SD pin
     * @param mode I2S working mode
     */
    I2s(GPIO_no sck, GPIO_no ws, GPIO_no sd, I2s_mode mode);
    I2s(I2s&) = delete; // copy constructor is deleted

    /**
     * @brief Read byte via I2S
     * @return Byte read
     */
    uint8_t read_byte();

    /**
     * @brief Write a byte over I2S
     * @param command Command
     */
    void write_byte(uint8_t command);

private:
    GPIO_no _sck;
    GPIO_no _ws;
    GPIO_no _sd;
    I2s_mode _mode;
};

#endif