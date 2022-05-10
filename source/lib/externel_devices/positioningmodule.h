#ifndef POSITIONINGMODULE_H
#define POSITIONINGMODULE_H

#include "../peripheral/uart.h"

#include <memory>

class PositioningModule {
public:
    PositioningModule(GPIO_no tx, GPIO_no rx)
    {
        _uart = std::make_unique<Uart>(tx, rx, 115200);
        // something more
    }
    PositioningModule(const PositioningModule&) = delete; // copy constructor is deleted

    double get_latitude();
    double get_longitude();

private:
    std::unique_ptr<Uart> _uart;
};

#endif