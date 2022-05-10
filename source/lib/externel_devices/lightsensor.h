#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#include "../peripheral/i2c.h"

#include <memory>

class LightSensor {
public:
    LightSensor(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    LightSensor(const LightSensor&) = delete; // copy constructor is deleted

    uint8_t read();
    void write(uint8_t data);

private:
    std::unique_ptr<I2c> _i2c;
};

#endif