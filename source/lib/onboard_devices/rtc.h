#ifndef RTC_H
#define RTC_H

#include "../peripheral/i2c.h"

#include <ctime>
#include <memory>

/**
 * @brief RTC management class
 */
class RTC {
public:
    /**
     * @brief Constructer of RTC class
     * @param sda SDA pin
     * @param scl SCL pin
     */
    RTC(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    RTC(const RTC&) = delete; // copy constructor is deleted

    /**
     * @brief Get unix_epoch time
     * @return Unix_epoch time
     */
    uint64_t get_unix_time();

    /**
     * @brief Get string time
     * @return String time
     */
    std::string get_time();

    /**
     * @brief Set time via unix epoch
     * @param unix_epoch Time
     */
    void set_time(uint64_t unix_epoch);

    /**
     * @brief Set time via CTIME object
     * @param time_t Time
     */
    void set_time(time_t ctime);

    /**
     * @brief Set time via string
     * @param stime Time
     */
    void set_time(std::string stime);

private:
    std::unique_ptr<I2c> _i2c;
};

#endif