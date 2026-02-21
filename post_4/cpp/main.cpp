#include "gpio.hpp"

volatile static unsigned int led_flag = 0;

int main(void)
{
    gpio_t green_led = {
		.gpio_base = GPIOA_BASE,
		.pin = 5U,
		.mode = GPIO_MODE_OUTPUT,
	};

    green_led.init();

    while(1)
    {
        for(int i=0 ; i<500000 ; i++) __asm__("NOP");
        if(led_flag == 1) {
            green_led.set();
            led_flag = 0;
        } else if (led_flag == 0) {
            green_led.clear();
            led_flag = 1;
        }
    }
}
