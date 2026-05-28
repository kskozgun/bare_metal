#pragma once
#include <stdint.h>
#include "stm32fxxx_regs.h"


// GPIO pin mode values (MODER field)
enum class gpio_mode_t{
    MODE_INPUT  = 0U,
    MODE_OUTPUT = 1U,
    MODE_ALT    = 2U,
    MODE_ANALOG = 3U,
};

// GPIO pin numbers
enum class gpio_pin_t {
    PIN_0  = 0U,
    PIN_1  = 1U,
    PIN_2  = 2U,
    PIN_3  = 3U,
    PIN_4  = 4U,
    PIN_5  = 5U,
    PIN_6  = 6U,
    PIN_7  = 7U,
    PIN_8  = 8U,
    PIN_9  = 9U,
    PIN_10 = 10U,
    PIN_11 = 11U,
    PIN_12 = 12U,
    PIN_13 = 13U,
    PIN_14 = 14U,
    PIN_15 = 15U,
};

class gpio_t {
public:
    /* Parameterized constructor */
    gpio_t(gpio_base_t gpio_base, gpio_pin_t pin, gpio_mode_t mode);

    /** Enable the port clock and configure the pin mode. */
    void init();

    /** Drive the pin HIGH. */
    void set();

    /** Drive the pin LOW. */
    void clear();

    /** Enable GPIO clock */
    inline void enable_gpio_clock(const uintptr_t gpio_base);

private:
    /*variables*/
    uintptr_t      gpio_base;
    gpio_pin_t     pin;
    gpio_mode_t    mode;
};