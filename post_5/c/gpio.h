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

/**
 * Represents a single GPIO pin.
 *  gpio_base : pointer to the port's register block (e.g. GPIOA_BASE)
 *  pin       : pin number 0-15
 *  mode      : GPIO_MODE_INPUT / OUTPUT / ALT / ANALOG
 */
typedef struct {
    GPIO_RegDef_t *gpio_base;
    gpio_pin_t pin;
    gpio_mode_t mode;
} gpio_t;

/** Enable the port clock and configure the pin mode. */
void gpio_init(gpio_t *gpio);

/** Drive the pin HIGH. */
void gpio_set(gpio_t *gpio);

/** Drive the pin LOW. */
void gpio_clear(gpio_t *gpio);