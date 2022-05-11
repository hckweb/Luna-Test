#ifndef SDIO_H
#define SDIO_H

#include "hardware_common.h"

#include <cstddef>
#include <cstdint>
#include <vector>

enum class Sdio_mode {
    HOST,
    SLAVE
};

class Sdio {
public:
    Sdio(GPIO_no cmd, GPIO_no clk, GPIO_no data0, GPIO_no data1, GPIO_no data2, GPIO_no data3, Sdio_mode mode);
    Sdio(Sdio&) = delete; // copy constructor is deleted

    std::vector<char> read_buffer();

    void write_buffer(std::vector<char> data);

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