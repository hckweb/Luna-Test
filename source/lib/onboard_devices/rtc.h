#ifndef RTC_H
#define RTC_H

#include "../peripheral/i2c.h"

#include <ctime>
#include <memory>

class RTC {
public:
    RTC(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    RTC(const RTC&) = delete; // copy constructor is deleted

    uint64_t get_unix_time();
    std::string get_time();

    void set_time(uint64_t unix_epoch);
    void set_time(time_t ctime);
    void set_time(std::string stime);

private:
    std::unique_ptr<I2c> _i2c;
};

#endif