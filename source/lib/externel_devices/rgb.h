#ifndef RGB_H
#define RGB_H

#include "../peripheral/pwm.h"

#include <memory>

/**
 * @brief RGB management class
 */
class Rgb {
public:
    /**
     * @brief Constructer of RGB management class
     * @param pin_r Red pin
     * @param pin_g Green pin
     * @param pin_b Blue pin
     */
    Rgb(GPIO_no pin_r, GPIO_no pin_g, GPIO_no pin_b)
    {
        _pwm_r = std::make_unique<Pwm>(pin_r);
        _pwm_g = std::make_unique<Pwm>(pin_g);
        _pwm_b = std::make_unique<Pwm>(pin_b);
        // something more
    }
    Rgb(const Rgb&) = delete; // copy constructor is deleted

    /**
     * @brief Set RGB colors
     * @param r Red value
     * @param g Green value
     * @param b Blue value
     */
    void set(uint8_t r, uint8_t g, uint8_t b);

    /**
     * @brief Set RGB colors as a 32bit RGB color
     * @param rgb RGB color
     */
    void set(uint32_t rgb);

    /**
     * @brief Get Red color value
     * @return Red color value
     */
    uint8_t get_r();

    /**
     * @brief Get Green color value
     * @return Green color value
     */
    uint8_t get_g();

    /**
     * @brief Get Blue color value
     * @return Blue color value
     */
    uint8_t get_b();

    /**
     * @brief Get 32bit RGB color
     * @return 32bit RGB color
     */
    uint32_t get_rgb();

private:
    std::unique_ptr<Pwm> _pwm_r;
    std::unique_ptr<Pwm> _pwm_g;
    std::unique_ptr<Pwm> _pwm_b;
};

#endif