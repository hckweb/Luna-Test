#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "../peripheral/i2c.h"

#include <ctime>
#include <memory>

class Temperature {
public:
    Temperature(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    Temperature(const Temperature&) = delete; // copy constructor is deleted

    double operator()(); // parenthesis operator to read temp

private:
    std::unique_ptr<I2c> _i2c;
};

#endif