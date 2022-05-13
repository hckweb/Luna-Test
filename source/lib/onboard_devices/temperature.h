#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../peripheral/i2c.h"

#include <ctime>
#include <memory>

/**
 * @brief Temperature sensor class that uses I2C comunucation protocol
 */
class Temperature {
public:
    /**
     * @brief Constructor of Temperature object
     * @param sda Data pin of I2C
     * @param scl Data pin of I2C
     */
    Temperature(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    Temperature(const Temperature&) = delete; // copy constructor is deleted

    /**
     * @brief Get the temperature
     * @return Temperature value
     */
    double operator()(); // parenthesis operator to read temp

private:
    std::unique_ptr<I2c> _i2c;
};

#endif