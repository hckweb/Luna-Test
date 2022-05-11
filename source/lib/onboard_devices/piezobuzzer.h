#ifndef PIEZOBUZZER_H
#define PIEZOBUZZER_H

#include "../peripheral/gpio.h"

#include <memory>

class PiezoBuzzer {
public:
    PiezoBuzzer(GPIO_no buzzer)
    {
        _buzzer = std::make_unique<Gpio>(buzzer, GPIO_mode::OUTPUT);
        // something more
    }
    PiezoBuzzer(const PiezoBuzzer&) = delete; // copy constructor is deleted

    void ring();
    void ring(uint32_t time_ms);
    void stop();

private:
    std::unique_ptr<Gpio> _buzzer;
};

#endif