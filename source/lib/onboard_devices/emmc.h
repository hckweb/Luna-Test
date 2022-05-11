#ifndef EMMC_H
#define EMMC_H

#include "../peripheral/i2c.h"

#include <memory>
#include <vector>

class EMMC {
public:
    EMMC(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    EMMC(const EMMC&) = delete; // copy constructor is deleted

    std::vector<char> read(uint32_t address, size_t size);
    void write(uint32_t address, std::vector<char> data);

private:
    std::unique_ptr<I2c> _i2c;
};

#endif