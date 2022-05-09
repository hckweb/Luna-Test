#ifndef HARDWARE_COMMON_H
#define HARDWARE_COMMON_H

enum class GPIO_status {
    LOW,
    HIGH
};

enum class GPIO_no {
    GPIO0,
    GPIO1,
    GPIO2,
    GPIO3,
    GPIO4,
    GPIO5,
    GPIO6,
    GPIO7,
    GPIO8,
    GPIO9,
    GPIO10,
    GPIO11,
    GPIO12,
    GPIO13,
    GPIO14,
    GPIO15,
    GPIO16,
    GPIO17,
    GPIO18,
    GPIO19
};
enum class GPIO_mode {
    INPUT,
    OUTPUT
};
enum class GPIO_pull_state {
    NONE,
    PULLDOWN,
    PULLUP
};
enum class GPIO_state {
    NONE,
    PUSHPULL,
    OPENDRAIN
};

#endif