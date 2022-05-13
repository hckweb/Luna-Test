#ifndef SDIO_H
#define SDIO_H

#include "hardware_common.h"

#include <cstddef>
#include <cstdint>
#include <vector>

/**
 * @brief SDIO mode struct. Use HOST or SLAVE
 */
enum class Sdio_mode {
    HOST,
    SLAVE
};

/**
 * @brief SDIO management class
 */
class Sdio {
public:
    /**
     * @brief Constructor of SDIO class
     * @param cmd CMD pin
     * @param clk CLK pin
     * @param data0 DATA0 pin
     * @param data1 DATA1 pin
     * @param data2 DATA2 pin
     * @param data3 DATA3 pin
     * @param mode SIOD mode
     */
    Sdio(GPIO_no cmd, GPIO_no clk, GPIO_no data0, GPIO_no data1, GPIO_no data2, GPIO_no data3, Sdio_mode mode);
    Sdio(Sdio&) = delete; // copy constructor is deleted

    /**
     * @brief Read a byte buffer
     * @return Buffer
     */
    std::vector<uint8_t> read_buffer();

    /**
     * @brief Read write byte buffer
     * @param data Data to send
     */
    void write_buffer(std::vector<uint8_t> data);

private:
    GPIO_no _cmd;
    GPIO_no _clk;
    GPIO_no _data0;
    GPIO_no _data1;
    GPIO_no _data2;
    GPIO_no _data3;
    Sdio_mode _mode;
};

#endif