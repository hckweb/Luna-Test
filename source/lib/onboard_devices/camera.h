#ifndef CAMERA_H
#define CAMERA_H

#include "../peripheral/usb.h"

#include <memory>
#include <vector>

class Pixel {
public:
    uint8_t R;
    uint8_t G;
    uint8_t B;
};

class Image {
public:
    Image(uint32_t horizontal, uint32_t vertical);

private:
    std::unique_ptr<std::vector<Pixel>> _rgbs;
};

class Camera {
public:
    Camera(uint16_t pid, uint16_t vid)
    {
        _usb = std::make_unique<Usb>(pid, vid);
        // something more
    }
    Camera(const Camera&) = delete; // copy constructor is deleted

    std::vector<Image> get_image();

private:
    std::unique_ptr<Usb> _usb;
    std::unique_ptr<std::vector<Image>> _images;
};

#endif