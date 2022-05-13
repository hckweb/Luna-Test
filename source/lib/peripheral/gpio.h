#ifndef GPIO_H
#define GPIO_H

#include "hardware_common.h"

/**
 * @brief GPIO management class
 */
class Gpio {
public:
    /**
     * @brief Constructor of SPI class
     * @param pin Pin no
     * @param mode Working mode
     * @param pull_state Pull state of pin
     * @param state State of pin
     */
    Gpio(GPIO_no pin, GPIO_mode mode = GPIO_mode::INPUT, GPIO_pull_state pull_state = GPIO_pull_state::NONE, GPIO_state state = GPIO_state::NONE);
    Gpio(const Gpio&) = delete; // copy constructor is deleted

    /**
     * @brief Get pin status
     * @return Pin status
     */
    GPIO_status read();

    /**
     * @brief Set pin status
     * @param status Pin status
     */
    void write(GPIO_status status);

    /**
     * @brief Toogle current pin status
     */
    void toogle();

    /**
     * @brief Set pin status to HIGH
     */
    void set();

    /**
     * @brief Set pin status to LOW
     */
    void clear();

    /**
     * @brief Get mode of pin
     * @return Pin mode
     */
    GPIO_mode get_mode();

    /**
     * @brief Get pull state of pin
     * @return Pin pull state
     */
    GPIO_pull_state get_pull_state();

    /**
     * @brief Get state of pin
     * @return Pin state
     */
    GPIO_state get_state();

    /**
     * @brief Change mode of pin
     * @param mode Mode of pin
     */
    void change_mode(GPIO_mode mode);

    /**
     * @brief Change pull state of pin
     * @param pull_state Pull state of pin
     */
    void change_pull_state(GPIO_pull_state pull_state);

    /**
     * @brief Change state of pin
     * @param state State of pin
     */
    void change_state(GPIO_state state);

private:
    GPIO_no _pin;
    GPIO_mode _mode;
    GPIO_pull_state _pull_state;
    GPIO_state _state;
};

#endif