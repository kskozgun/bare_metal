#include "gpio.h"

/*
 * Each STM32F4 GPIO port is GPIO_PORT_STRIDE bytes apart starting from
 * GPIO_PORT_BASE_ADDR. The port index maps directly to the RCC AHB1ENR
 * clock-enable bit: 0 = GPIOA, 1 = GPIOB, 2 = GPIOC, ...
 */
static void enable_gpio_clock(const GPIO_RegDef_t *gpio_base)
{
    uint32_t port_idx = ((uint32_t)(uintptr_t)gpio_base - GPIO_PORT_BASE_ADDR)
                        / GPIO_PORT_STRIDE;
    RCC_AHB1ENR |= (1U << port_idx);
}

void gpio_init(gpio_t *gpio)
{
    // 1. Enable the peripheral clock for this GPIO port
    enable_gpio_clock(gpio->gpio_base);

    // 2. Configure the MODER register (GPIO_MODER_BITS_PER_PIN bits per pin)
    //    Clear the two mode bits, then write the requested mode
    uint8_t shift = gpio->pin * GPIO_MODER_BITS_PER_PIN;
    gpio->gpio_base->MODER &= ~(GPIO_MODER_PIN_MASK << shift);
    gpio->gpio_base->MODER |=  ((gpio->mode & GPIO_MODER_PIN_MASK) << shift);
}

void gpio_set(gpio_t *gpio)
{
    gpio->gpio_base->ODR |= (1U << gpio->pin);
}

void gpio_clear(gpio_t *gpio)
{
    gpio->gpio_base->ODR &= ~(1U << gpio->pin);
}
