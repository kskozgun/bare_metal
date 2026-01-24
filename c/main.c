// STM32F4xxx peripheral base addresses
#define RCC_BASE    0x40023800
#define GPIOA_BASE  0x40020000

// RCC register offsets
#define RCC_AHB1ENR_OFFSET  0x30

// GPIO register offsets
#define GPIO_MODER_OFFSET   0x00
#define GPIO_ODR_OFFSET     0x14

// Define RCC and GPIOA as pointers to volatile uint32_t
#define RCC_AHB1ENR   (*((volatile unsigned int *)(RCC_BASE + RCC_AHB1ENR_OFFSET)))
#define GPIOA_MODER   (*((volatile unsigned int *)(GPIOA_BASE + GPIO_MODER_OFFSET)))
#define GPIOA_ODR     (*((volatile unsigned int *)(GPIOA_BASE + GPIO_ODR_OFFSET)))

#define AHB_GPIOA_EN_POS   (1U<<0)

void green_led_init(void)
{
	// Initialize AHB1 GPIOA clock
	RCC_AHB1ENR |= AHB_GPIOA_EN_POS;

	// Set GPIO as output
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);
}

void green_led_on(void)
{
	GPIOA_ODR |= ( 1U << 5);
}

void green_led_off(void)
{
	GPIOA_ODR &= ~( 1U << 5);
}

volatile static unsigned int led_flag = 0;

int main(void)
{
    green_led_init();

    while(1)
    {
        for(int i=0 ; i<500000 ; i++) __asm__("NOP");
        if(led_flag == 1) {
		 	green_led_on();
		 	led_flag = 0;
		} else if (led_flag == 0) {
		 	green_led_off();
		 	led_flag = 1;
		}
    }
}
