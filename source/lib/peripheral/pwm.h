#ifndef PWM_H
#define PWM_H

#include "hardware_common.h"

#include <cstdint>

/**
 * @brief PWM management class
 */
class Pwm {
public:
    /**
     * @brief Constructor of PWM class
     * @param pin GPIO pin
     */
    Pwm(GPIO_no pin);
    Pwm(const Pwm&) = delete; // copy constructor is deleted

    /**
     * @brief Start PWM
     */
    void start();

    /**
     * @brief Stop PWM
     */
    void stop();

    /**
     * @brief Get frequency
     * @return Frequency
     */
    uint32_t get_freq();

    /**
     * @brief Get duty
     * @return Duty
     */
    double get_duty();

    /**
     * @brief Set frequency
     * @param freq Frequency
     */
    void set_freq(uint32_t freq);

    /**
     * @brief Set duty
     * @param duty Duty
     */
    void set_duty(double duty);

private:
    GPIO_no _pin;
    uint32_t _freq;
    double _duty;
};

#endif