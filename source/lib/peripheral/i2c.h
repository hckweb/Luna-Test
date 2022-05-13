#ifndef I2C_H
#define I2C_H

#include "hardware_common.h"

#include <cstdint>

/**
 * @brief I2C mode struct. Use MASTER or SLAVE
 */
enum class I2c_mode {
    MASTER,
    SLAVE
};

/**
 * @brief I2C communucation class
 */
class I2c {
public:
    /**
     * @brief Constructor of I2C class
     * @param sda SDA pin
     * @param scl SCL pin
     * @param type I2C mode
     * @param speed I2C speed
     * @param sda_pull_up SDA pin internal pull up
     * @param scl_pull_up SCL pin internal pull up
     */
    I2c(GPIO_no sda, GPIO_no scl, I2c_mode type, uint32_t speed, bool sda_pull_up, bool scl_pull_up);
    I2c(I2c&) = delete; // copy constructor is deleted

    /**
     * @brief Start I2C communucation
     */
    void start();

    /**
     * @brief Stop I2C communucation
     */
    void stop();

    /**
     * @brief Read a byte via I2C
     * @return A byte read
     */
    uint8_t read_byte();

    /**
     * @brief Write a byte to a specific device
     * @param command Command to write
     * @param slave_address Adress to send data
     */
    void write_byte(uint8_t command, uint8_t slave_address);

private:
    GPIO_no _sda;
    GPIO_no _scl;
    I2c_mode _type;
    uint32_t _speed;
};

#endif