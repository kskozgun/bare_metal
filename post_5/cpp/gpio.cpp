#include "gpio.hpp"
#include "stm32fxxx_regs.h"

/*
 * Each STM32F4 GPIO port is GPIO_PORT_STRIDE bytes apart starting from
 * GPIO_PORT_BASE_ADDR. The port index maps directly to the RCC AHB1ENR
 * clock-enable bit: 0 = GPIOA, 1 = GPIOB, 2 = GPIOC, ...
 */
inline void gpio_t::enable_gpio_clock(const GPIO_RegDef_t *gpio_base)
{
    uint32_t port_idx = ((uint32_t)(uintptr_t)gpio_base - GPIO_PORT_BASE_ADDR)
                        / GPIO_PORT_STRIDE;
    RCC_AHB1ENR |= (1U << port_idx);
}

gpio_t::gpio_t(GPIO_RegDef_t *GPIO_RegDef, gpio_pin_t pin, gpio_mode_t mode)
{
    this->gpio_base = GPIO_RegDef;
    this->pin = pin;
    this->mode = mode;
}

void gpio_t::init()
{
    // 1. Enable the peripheral clock for this GPIO port
    enable_gpio_clock(gpio_base);

    // 2. Configure the MODER register (MODER_BITS_PER_PIN bits per pin)
    //    Clear the two mode bits, then write the requested mode
    uint8_t shift = this->pin * GPIO_MODER_BITS_PER_PIN;
    gpio_base->MODER &= ~(GPIO_MODER_PIN_MASK << shift);
    gpio_base->MODER |=  ((this->mode & GPIO_MODER_PIN_MASK) << shift);
}

void gpio_t::set()
{
    gpio_base->ODR |= (1U << pin);
}

void gpio_t::clear()
{
    gpio_base->ODR &= ~(1U << pin);
}
