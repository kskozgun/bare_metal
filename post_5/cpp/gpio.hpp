#pragma once
#include <stdint.h>
#include "stm32fxxx_regs.h"


// GPIO pin mode values (MODER field)
typedef enum {
    GPIO_MODE_INPUT  = 0U,
    GPIO_MODE_OUTPUT = 1U,
    GPIO_MODE_ALT    = 2U,
    GPIO_MODE_ANALOG = 3U,
} gpio_mode_t;

// GPIO pin numbers
typedef enum {
    GPIO_PIN_0  = 0U,
    GPIO_PIN_1  = 1U,
    GPIO_PIN_2  = 2U,
    GPIO_PIN_3  = 3U,
    GPIO_PIN_4  = 4U,
    GPIO_PIN_5  = 5U,
    GPIO_PIN_6  = 6U,
    GPIO_PIN_7  = 7U,
    GPIO_PIN_8  = 8U,
    GPIO_PIN_9  = 9U,
    GPIO_PIN_10 = 10U,
    GPIO_PIN_11 = 11U,
    GPIO_PIN_12 = 12U,
    GPIO_PIN_13 = 13U,
    GPIO_PIN_14 = 14U,
    GPIO_PIN_15 = 15U,
} gpio_pin_t;

class gpio_t {
public:
    /* Parameterized constructor */
    gpio_t(GPIO_RegDef_t *GPIO_RegDef, gpio_pin_t pin, gpio_mode_t mode);

    /** Enable the port clock and configure the pin mode. */
    void init();

    /** Drive the pin HIGH. */
    void set();

    /** Drive the pin LOW. */
    void clear();

    /** Enable GPIO clock */
    inline void enable_gpio_clock(const GPIO_RegDef_t *gpio_base);

private:
    /*variables*/
    GPIO_RegDef_t *gpio_base;
    uint8_t        pin;
    uint8_t        mode;
};