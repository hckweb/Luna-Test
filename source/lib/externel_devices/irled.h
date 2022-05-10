#ifndef IRLED_H
#define IRLED_H

#include "../peripheral/gpio.h"

#include <memory>

class IrLed {
public:
    IrLed(GPIO_no pin)
    {
        _gpio = std::make_unique<Gpio>(pin);
        // something more
    }
    IrLed(const IrLed&) = delete; // copy constructor is deleted

    uint8_t read();
    void write(uint8_t data);

private:
    std::unique_ptr<Gpio> _gpio;
};

#endif