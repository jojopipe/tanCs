#ifndef TANCS_SETTINGS_H
#define TANCS_SETTINGS_H

#include <stdint.h>

struct window_parameters {
    uint16_t width;
    uint16_t height;
    uint8_t window_state; //0: windowed, 1: borderless, 2: fullscreen
};

#endif //TANCS_SETTINGS_H
