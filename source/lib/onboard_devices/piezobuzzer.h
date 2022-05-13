#ifndef PIEZOBUZZER_H
#define PIEZOBUZZER_H

#include "../peripheral/gpio.h"

#include <memory>

/**
 * @brief Piezo buzzer management class
 */
class PiezoBuzzer {
public:
    /**
     * @brief Constructer of piezo buzzer class
     * @param buzzer Buzzer pin no
     */
    PiezoBuzzer(GPIO_no buzzer)
    {
        _buzzer = std::make_unique<Gpio>(buzzer, GPIO_mode::OUTPUT);
        // something more
    }
    PiezoBuzzer(const PiezoBuzzer&) = delete; // copy constructor is deleted

    /**
     * @brief Ring the buzzer
     */
    void ring();

    /**
     * @brief Ring the buzzer for time_ms miliseconds
     */
    void ring(uint32_t time_ms);

    /**
     * @brief Stop the buzzer
     */
    void stop();

private:
    std::unique_ptr<Gpio> _buzzer;
};

#endif