#pragma once
#include <stdint.h>
#include "stm32fxxx_regs.h"

// GPIO pin mode values (MODER field)
#define GPIO_MODE_INPUT     0U
#define GPIO_MODE_OUTPUT    1U
#define GPIO_MODE_ALT       2U
#define GPIO_MODE_ANALOG    3U

/**
 * Represents a single GPIO pin.
 *  gpio_base : pointer to the port's register block (e.g. GPIOA_BASE)
 *  pin       : pin number 0-15
 *  mode      : GPIO_MODE_INPUT / OUTPUT / ALT / ANALOG
 */
typedef struct {
    GPIO_RegDef_t *gpio_base;
    uint8_t pin;
    uint8_t mode;
} gpio_t;

/** Enable the port clock and configure the pin mode. */
void gpio_init(gpio_t *gpio);

/** Drive the pin HIGH. */
void gpio_set(gpio_t *gpio);

/** Drive the pin LOW. */
void gpio_clear(gpio_t *gpio);