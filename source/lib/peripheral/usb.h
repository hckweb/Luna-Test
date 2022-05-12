#ifndef USB_H
#define USB_H

#include <cstdint>
#include <iosfwd>

class Usb {
public:
    Usb(uint16_t pid, uint16_t vid);
    Usb(const Usb&) = delete; // copy constructor is deleted

    // functions for << operator
    Usb& operator<<(bool val);
    Usb& operator<<(short val);
    Usb& operator<<(unsigned short val);
    Usb& operator<<(int val);
    Usb& operator<<(unsigned int val);
    Usb& operator<<(long val);
    Usb& operator<<(unsigned long val);
    Usb& operator<<(long long val);
    Usb& operator<<(unsigned long long val);
    Usb& operator<<(float val);
    Usb& operator<<(double val);
    Usb& operator<<(long double val);
    Usb& operator<<(void* val);
    Usb& operator<<(std::streambuf* sb);
    Usb& operator<<(Usb& (*pf)(Usb&));
    Usb& operator<<(std::ios& (*pf)(std::ios&));
    Usb& operator<<(std::ios_base& (*pf)(std::ios_base&));

    // functions for output and input streams
    friend std::ostream& operator<<(std::ostream& os, const Usb& data);
    friend std::istream& operator>>(std::istream& is, Usb& data);

private:
    uint16_t _pid;
    uint16_t _vid;
};

#endif