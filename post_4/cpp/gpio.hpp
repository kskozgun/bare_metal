#pragma once
#include <stdint.h>
#include "stm32fxxx_regs.h"

// GPIO pin mode values (MODER field)
#define GPIO_MODE_INPUT   0U
#define GPIO_MODE_OUTPUT  1U
#define GPIO_MODE_ALT     2U
#define GPIO_MODE_ANALOG  3U

class gpio_t {
public:
    /** Enable the port clock and configure the pin mode. */
    void init();

    /** Drive the pin HIGH. */
    void set();

    /** Drive the pin LOW. */
    void clear();

    /**/
    void enable_gpio_clock(const GPIO_RegDef_t *gpio_base);

    /*variables*/
    GPIO_RegDef_t *gpio_base;
    uint8_t        pin;
    uint8_t        mode;
};