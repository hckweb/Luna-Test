#ifndef POSITIONINGMODULE_H
#define POSITIONINGMODULE_H

#include "../peripheral/uart.h"

#include <memory>

/**
 * @brief GPS module management class
 */
class PositioningModule {
public:
    /**
     * @brief Constructer of GPS class
     * @param tx TX pin
     * @param rx RX pin
     */
    PositioningModule(GPIO_no tx, GPIO_no rx)
    {
        _uart = std::make_unique<Uart>(tx, rx, 115200);
        // something more
    }
    PositioningModule(const PositioningModule&) = delete; // copy constructor is deleted

    /**
     * @brief Get latitude value
     * @return Latitude value
     */
    double get_latitude();

    /**
     * @brief Get longitude value
     * @return Longitude value
     */
    double get_longitude();

private:
    std::unique_ptr<Uart> _uart;
};

#endif