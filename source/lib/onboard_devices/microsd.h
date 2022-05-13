#ifndef MICROSD_H
#define MICROSD_H

#include "../peripheral/i2c.h"

#include <memory>
#include <vector>

/**
 * @brief Micro SD management class
 */
class MicroSD {
public:
    /**
     * @brief Constructer of Micro SD class
     * @param sda SDA pin
     * @param scl SCL pin
     */
    MicroSD(GPIO_no sda, GPIO_no scl)
    {
        _i2c = std::make_unique<I2c>(sda, scl, I2c_mode::MASTER, 400'000, true, true);
        // something more
    }
    MicroSD(const MicroSD&) = delete; // copy constructor is deleted

    /**
     * @brief Read data via Micro SD
     * @param address Address to start read
     * @param size Byte to read
     * @return Data read
     */
    std::vector<uint8_t> read(uint32_t address, size_t size);

    /**
     * @brief Write data over Micro SD
     * @param address Address to start write
     * @param data Data to write
     */
    void write(uint32_t address, std::vector<uint8_t> data);

private:
    std::unique_ptr<I2c> _i2c;
};

#endif