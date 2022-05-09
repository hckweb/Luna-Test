#ifndef PWM_H
#define PWM_H

#include "hardware_common.h"

#include <cstdint>

class Pwm {
public:
    Pwm(GPIO_no pin);
    Pwm(const Pwm&) = delete; // copy constructor is deleted

    void start();
    void stop();

    uint32_t get_freq();
    double get_duty();

    void set_freq(uint32_t freq);
    void set_duty(double duty);

private:
    GPIO_no _pin;
    uint32_t _freq;
    double _duty;
};

#endif