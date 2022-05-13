#ifndef BATTARYMONITOR_H
#define BATTARYMONITOR_H

#include "../peripheral/i2c.h"

#include <memory>

/**
 * @brief Battery monitoring class
 */
class BatteryMonitor {
public:
    /**
     * @brief Constructer of Battery Monitor class
     * @param sda SDA pin
     * @param scl SCL pin
     */
    BatteryMonitor(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    BatteryMonitor(const BatteryMonitor&) = delete; // copy constructor is deleted

    /**
     * @brief Read current battery percent
     */
    double read();

private:
    std::unique_ptr<I2c> _i2c;
};

#endif