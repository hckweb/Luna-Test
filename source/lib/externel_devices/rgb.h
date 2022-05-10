#ifndef RGB_H
#define RGB_H

#include "../peripheral/pwm.h"

#include <memory>

class Rgb {
public:
    Rgb(GPIO_no pin_r, GPIO_no pin_g, GPIO_no pin_b)
    {
        _pwm_r = std::make_unique<Pwm>(pin_r);
        _pwm_g = std::make_unique<Pwm>(pin_g);
        _pwm_b = std::make_unique<Pwm>(pin_b);
        // something more
    }
    Rgb(const Rgb&) = delete; // copy constructor is deleted

    void set(uint8_t r, uint8_t g, uint8_t b);
    void set(uint32_t rgb);

    uint8_t get_r();
    uint8_t get_g();
    uint8_t get_b();
    uint32_t get_rgb();

private:
    std::unique_ptr<Pwm> _pwm_r;
    std::unique_ptr<Pwm> _pwm_g;
    std::unique_ptr<Pwm> _pwm_b;
};

#endif