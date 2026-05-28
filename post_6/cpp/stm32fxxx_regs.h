#pragma once
#include <stdint.h>

// -------------------------------------------------------
// RCC
// -------------------------------------------------------
#define RCC_BASE            0x40023800U
#define RCC_AHB1ENR_OFFSET  0x30U
#define RCC_AHB1ENR         (*((volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET)))

// -------------------------------------------------------
// GPIO register map
// -------------------------------------------------------
typedef struct {
    volatile uint32_t MODER;    /* 0x00 - Mode register              */
    volatile uint32_t OTYPER;   /* 0x04 - Output type register       */
    volatile uint32_t OSPEEDR;  /* 0x08 - Output speed register      */
    volatile uint32_t PUPDR;    /* 0x0C - Pull-up/pull-down register */
    volatile uint32_t IDR;      /* 0x10 - Input data register        */
    volatile uint32_t ODR;      /* 0x14 - Output data register       */
    volatile uint32_t BSRR;     /* 0x18 - Bit set/reset register     */
} GPIO_RegDef_t;

// GPIO port base addresses
#define GPIO_PORT_BASE_ADDR  0x40020000U   /* Raw address of GPIOA (for arithmetic) */
#define GPIO_PORT_STRIDE     0x400U        /* Bytes between consecutive GPIO ports  */

enum class gpio_base_t {
    PORT_A = 0x40020000U,
    PORT_B = 0x40020400U,
    PORT_C = 0x40020800U,
    PORT_D = 0x40020C00U,
    PORT_E = 0x40021000U,
};

// GPIO MODER field constants (2 bits per pin)
#define GPIO_MODER_BITS_PER_PIN  2U
#define GPIO_MODER_PIN_MASK      3U   /* 0b11 - mask for one pin's MODER field */