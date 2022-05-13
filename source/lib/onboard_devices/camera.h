#ifndef CAMERA_H
#define CAMERA_H

#include "../peripheral/usb.h"

#include <memory>
#include <vector>

/**
 * @brief Pixel class that can hold 24bit color data
 */
class Pixel {
public:
    /**
     * @brief Red color value of Pixel
     */
    uint8_t R;

    /**
     * @brief Green color value of Pixel
     */
    uint8_t G;

    /**
     * @brief Blue color value of Pixel
     */
    uint8_t B;
};

/**
 * @brief Image class that can hold a raw image
 */
class Image {
public:
    /**
     * @brief Constructer of Image class
     * @param horizontal Horizontal pixel size of image
     * @param vertical Vertical pixel size of image
     */
    Image(uint32_t horizontal, uint32_t vertical);

private:
    std::unique_ptr<std::vector<Pixel>> _rgbs;
};

/**
 * @brief Camera management class
 */
class Camera {
public:
    /**
     * @brief Constructer of Camera class
     * @param pid USB PID of Camera device
     * @param vid USB VID of Camera device
     */
    Camera(uint16_t pid, uint16_t vid)
    {
        _usb = std::make_unique<Usb>(pid, vid);
        // something more
    }
    Camera(const Camera&) = delete; // copy constructor is deleted

    /**
     * @brief Get a image over camera
     * @return Return a Image object
     */
    Image get_image();

private:
    std::unique_ptr<Usb> _usb;
    std::unique_ptr<std::vector<Image>> _images;
};

#endif