#ifndef GPIO_H
#define GPIO_H

#include "hardware_common.h"

class Gpio {
public:
    Gpio(GPIO_no pin, GPIO_mode mode = GPIO_mode::INPUT, GPIO_pull_state pull_state = GPIO_pull_state::NONE, GPIO_state state = GPIO_state::NONE);
    Gpio(const Gpio&) = delete; // copy constructor is deleted

    GPIO_status read();
    void write(GPIO_status status);
    void toogle();

    void set();
    void clear();

    GPIO_mode get_mode();
    GPIO_pull_state get_pull_state();
    GPIO_state get_state();

    void change_mode(GPIO_mode mode);
    void change_pull_state(GPIO_pull_state pull_state);
    void change_state(GPIO_state state);

private:
    GPIO_no _pin;
    GPIO_mode _mode;
    GPIO_pull_state _pull_state;
    GPIO_state _state;
};

#endif