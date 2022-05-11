#ifndef LEDS_H
#define LEDS_H

#include "../peripheral/gpio.h"

#include <memory>

class Led {
public:
    Led(GPIO_no led)
    {
        _led = std::make_unique<Gpio>(led, GPIO_mode::OUTPUT);
        // something more
    }
    Led(const Led&) = delete; // copy constructor is deleted

    void set();
    void clear();

private:
    std::unique_ptr<Gpio> _led;
};
/*
//Example code
void init_onboard_leds()
{
    Led power_led(GPIO_no::GPIO0);
    power_led.set();

    Led status_led(GPIO_no::GPIO1);
    status_led.set();
}
*/

#endif