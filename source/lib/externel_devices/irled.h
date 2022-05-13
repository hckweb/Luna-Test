#ifndef IRLED_H
#define IRLED_H

#include "../peripheral/gpio.h"

#include <memory>

/**
 * @brief IR LED management class
 */
class IrLed {
public:
    /**
     * @brief Constructor of IR LED class
     * @param pin IR LED pin
     */
    IrLed(GPIO_no pin)
    {
        _gpio = std::make_unique<Gpio>(pin);
        // something more
    }
    IrLed(const IrLed&) = delete; // copy constructor is deleted

    /**
     * @brief Read data from IR LED
     * @return Data to read
     */
    uint8_t read();

    /**
     * @brief Write data to IR LED
     * @param data Data to write
     */
    void write(uint8_t data);

private:
    std::unique_ptr<Gpio> _gpio;
};

#endif