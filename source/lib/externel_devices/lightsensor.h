#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "../peripheral/i2c.h"

#include <memory>

/**
 * @brief Light sensor managelent class
 */
class LightSensor {
public:
    /**
     * @brief Constructor of Light sensor class
     * @param sda SDA pin
     * @param scl SCL pin
     */
    LightSensor(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    LightSensor(const LightSensor&) = delete; // copy constructor is deleted

    /**
     * @brief Read light sensor data
     * @return Data to read
     */
    uint8_t read();

private:
    std::unique_ptr<I2c> _i2c;
};

#endif