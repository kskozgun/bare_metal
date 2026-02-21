#include "gpio.h"
#include "stm32fxxx_regs.h"

volatile static unsigned int led_flag = 0;

int main(void)
{
	gpio_t green_led = {
		.gpio_base = GPIOA_BASE,
		.pin = 5U,
		.mode = 1U,
	};

    gpio_init(&green_led);

    while(1)
    {
        for(int i=0 ; i<500000 ; i++) __asm__("NOP");
        if(led_flag == 1) {
		 	gpio_set(&green_led);
		 	led_flag = 0;
		} else if (led_flag == 0) {
		 	gpio_clear(&green_led);
		 	led_flag = 1;
		}
    }
}
