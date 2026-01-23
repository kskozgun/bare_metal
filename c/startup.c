#include <stdint.h>

// Linker symbols (these are addresses, not pointers)
extern uint32_t _sidata;  // Start of .data in FLASH (LMA)
extern uint32_t _sdata;   // Start of .data in RAM (VMA)
extern uint32_t _edata;   // End of .data in RAM
extern uint32_t _sbss;    // Start of .bss
extern uint32_t _ebss;    // End of .bss

extern int main();

void default_handler(void);
void Reset_Handler(void) __attribute__((noreturn));

// Weak aliases - all handlers default to default_handler
void NMI_Handler(void)              __attribute__((weak, alias("default_handler")));
void HardFault_Handler(void)        __attribute__((weak, alias("default_handler")));
void MemManage_Handler(void)        __attribute__((weak, alias("default_handler")));
void BusFault_Handler(void)         __attribute__((weak, alias("default_handler")));
void UsageFault_Handler(void)       __attribute__((weak, alias("default_handler")));
void SVC_Handler(void)              __attribute__((weak, alias("default_handler")));
void DebugMon_Handler(void)         __attribute__((weak, alias("default_handler")));
void PendSV_Handler(void)           __attribute__((weak, alias("default_handler")));
void SysTick_Handler(void)          __attribute__((weak, alias("default_handler")));
void WWDG_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void PVD_IRQHandler(void)           __attribute__((weak, alias("default_handler")));
void TAMP_STAMP_IRQHandler(void)    __attribute__((weak, alias("default_handler")));
void RTC_WKUP_IRQHandler(void)      __attribute__((weak, alias("default_handler")));
void FLASH_IRQHandler(void)         __attribute__((weak, alias("default_handler")));
void RCC_IRQHandler(void)           __attribute__((weak, alias("default_handler")));
void EXTI0_IRQHandler(void)         __attribute__((weak, alias("default_handler")));
void EXTI1_IRQHandler(void)         __attribute__((weak, alias("default_handler")));
void EXTI2_IRQHandler(void)         __attribute__((weak, alias("default_handler")));
void EXTI3_IRQHandler(void)         __attribute__((weak, alias("default_handler")));
void EXTI4_IRQHandler(void)         __attribute__((weak, alias("default_handler")));
void DMA1_Stream0_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA1_Stream1_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA1_Stream2_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA1_Stream3_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA1_Stream4_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA1_Stream5_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA1_Stream6_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void ADC_IRQHandler(void)           __attribute__((weak, alias("default_handler")));
void EXTI9_5_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void TIM1_BRK_TIM9_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_UP_TIM10_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void) __attribute__((weak, alias("default_handler")));
void TIM1_CC_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void TIM2_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void TIM3_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void TIM4_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void I2C1_EV_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void I2C1_ER_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void I2C2_EV_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void I2C2_ER_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void SPI1_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void SPI2_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void USART1_IRQHandler(void)        __attribute__((weak, alias("default_handler")));
void USART2_IRQHandler(void)        __attribute__((weak, alias("default_handler")));
void EXTI15_10_IRQHandler(void)     __attribute__((weak, alias("default_handler")));
void RTC_Alarm_IRQHandler(void)     __attribute__((weak, alias("default_handler")));
void OTG_FS_WKUP_IRQHandler(void)   __attribute__((weak, alias("default_handler")));
void DMA1_Stream7_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void SDIO_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void TIM5_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void SPI3_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void DMA2_Stream0_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA2_Stream1_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA2_Stream2_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA2_Stream3_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA2_Stream4_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void OTG_FS_IRQHandler(void)        __attribute__((weak, alias("default_handler")));
void DMA2_Stream5_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA2_Stream6_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void DMA2_Stream7_IRQHandler(void)  __attribute__((weak, alias("default_handler")));
void USART6_IRQHandler(void)        __attribute__((weak, alias("default_handler")));
void I2C3_EV_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void I2C3_ER_IRQHandler(void)       __attribute__((weak, alias("default_handler")));
void SPI4_IRQHandler(void)          __attribute__((weak, alias("default_handler")));
void SPI5_IRQHandler(void)          __attribute__((weak, alias("default_handler")));



// Vector table initialization
uint32_t vector_table[] __attribute__((section(".vector_table_sec"))) = {
    (uint32_t)&Reset_Handler,                   /* Reset Handler                                                      */
    (uint32_t)&NMI_Handler,                     /* NMI Handler                                                        */
    (uint32_t)&HardFault_Handler,               /* Hard Fault Handler                                                 */
    (uint32_t)&MemManage_Handler,               /* MPU Fault Handler                                                  */
    (uint32_t)&BusFault_Handler,                /* Bus Fault Handler                                                  */
    (uint32_t)&UsageFault_Handler,              /* Usage Fault Handler                                                */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    (uint32_t)&SVC_Handler,                     /* SVCall Handler                                                     */
    (uint32_t)&DebugMon_Handler,                /* Debug Monitor Handler                                              */
    0,                                          /* Reserved                                                           */
    (uint32_t)&PendSV_Handler,                  /* PendSV Handler                                                     */
    (uint32_t)&SysTick_Handler,                 /* SysTick Handler                                                    */
    (uint32_t)&WWDG_IRQHandler,                 /* Window Watchdog interrupt                                          */
    (uint32_t)&PVD_IRQHandler,                  /* EXTI Line 16 interrupt / PVD through EXTI                          */
    (uint32_t)&TAMP_STAMP_IRQHandler,           /* Tamper and TimeStamp interrupts through                            */
    (uint32_t)&RTC_WKUP_IRQHandler,             /* RTC Wakeup interrupt through the EXTI line                         */
    (uint32_t)&FLASH_IRQHandler,                /* FLASH global interrupt                                             */
    (uint32_t)&RCC_IRQHandler,                  /* RCC global interrupt                                               */
    (uint32_t)&EXTI0_IRQHandler,                /* EXTI Line0 interrupt                                               */
    (uint32_t)&EXTI1_IRQHandler,                /* EXTI Line1 interrupt                                               */
    (uint32_t)&EXTI2_IRQHandler,                /* EXTI Line2 interrupt                                               */
    (uint32_t)&EXTI3_IRQHandler,                /* EXTI Line3 interrupt                                               */
    (uint32_t)&EXTI4_IRQHandler,                /* EXTI Line4 interrupt                                               */
    (uint32_t)&DMA1_Stream0_IRQHandler,         /* DMA1 Stream0 global interrupt                                      */
    (uint32_t)&DMA1_Stream1_IRQHandler,         /* DMA1 Stream1 global interrupt                                      */
    (uint32_t)&DMA1_Stream2_IRQHandler,         /* DMA1 Stream2 global interrupt                                      */
    (uint32_t)&DMA1_Stream3_IRQHandler,         /* DMA1 Stream3 global interrupt                                      */
    (uint32_t)&DMA1_Stream4_IRQHandler,         /* DMA1 Stream4 global interrupt                                      */
    (uint32_t)&DMA1_Stream5_IRQHandler,         /* DMA1 Stream5 global interrupt                                      */
    (uint32_t)&DMA1_Stream6_IRQHandler,         /* DMA1 Stream6 global interrupt                                      */
    (uint32_t)&ADC_IRQHandler,                  /* ADC1 global interrupt                                              */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    (uint32_t)&EXTI9_5_IRQHandler,              /* EXTI Line[9:5] interrupts                                          */
    (uint32_t)&TIM1_BRK_TIM9_IRQHandler,        /* TIM1 Break interrupt and TIM9 global interrupt                     */
    (uint32_t)&TIM1_UP_TIM10_IRQHandler,        /* TIM1 Update interrupt and TIM10 global interrupt                   */
    (uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,   /* TIM1 Trigger and Commutation interrupts and TIM11 global interrupt */
    (uint32_t)&TIM1_CC_IRQHandler,              /* TIM1 Capture Compare interrupt                                     */
    (uint32_t)&TIM2_IRQHandler,                 /* TIM2 global interrupt                                              */
    (uint32_t)&TIM3_IRQHandler,                 /* TIM3 global interrupt                                              */
    (uint32_t)&TIM4_IRQHandler,                 /* TIM4 global interrupt                                              */
    (uint32_t)&I2C1_EV_IRQHandler,              /* I2C1 event interrupt                                               */
    (uint32_t)&I2C1_ER_IRQHandler,              /* I2C1 error interrupt                                               */
    (uint32_t)&I2C2_EV_IRQHandler,              /* I2C2 event interrupt                                               */
    (uint32_t)&I2C2_ER_IRQHandler,              /* I2C2 error interrupt                                               */
    (uint32_t)&SPI1_IRQHandler,                 /* SPI1 global interrupt                                              */
    (uint32_t)&SPI2_IRQHandler,                 /* SPI2 global interrupt                                              */
    (uint32_t)&USART1_IRQHandler,               /* USART1 global interrupt                                            */
    (uint32_t)&USART2_IRQHandler,               /* USART2 global interrupt                                            */
    0,                                          /* Reserved                                                           */
    (uint32_t)&EXTI15_10_IRQHandler,            /* EXTI Line[15:10] interrupts                                        */
    (uint32_t)&RTC_Alarm_IRQHandler,            /* RTC Alarms (A and B) through EXTI line interrupt                   */
    (uint32_t)&OTG_FS_WKUP_IRQHandler,          /* USB On-The-Go FS Wakeup through EXTI line interrupt                */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    (uint32_t)&DMA1_Stream7_IRQHandler,         /* DMA1 Stream7 global interrupt                                      */
    0,                                          /* Reserved                                                           */
    (uint32_t)&SDIO_IRQHandler,                 /* SDIO global interrupt                                              */
    (uint32_t)&TIM5_IRQHandler,                 /* TIM5 global interrupt                                              */
    (uint32_t)&SPI3_IRQHandler,                 /* SPI3 global interrupt                                              */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    (uint32_t)&DMA2_Stream0_IRQHandler,         /* DMA2 Stream0 global interrupt                                      */
    (uint32_t)&DMA2_Stream1_IRQHandler,         /* DMA2 Stream1 global interrupt                                      */
    (uint32_t)&DMA2_Stream2_IRQHandler,         /* DMA2 Stream2 global interrupt                                      */
    (uint32_t)&DMA2_Stream3_IRQHandler,         /* DMA2 Stream3 global interrupt                                      */
    (uint32_t)&DMA2_Stream4_IRQHandler,         /* DMA2 Stream4 global interrupt                                      */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    (uint32_t)&OTG_FS_IRQHandler,               /* USB On The Go FS global interrupt                                  */
    (uint32_t)&DMA2_Stream5_IRQHandler,         /* DMA2 Stream5 global interrupt                                      */
    (uint32_t)&DMA2_Stream6_IRQHandler,         /* DMA2 Stream6 global interrupt                                      */
    (uint32_t)&DMA2_Stream7_IRQHandler,         /* DMA2 Stream7 global interrupt                                      */
    (uint32_t)&USART6_IRQHandler,               /* USART6 global interrupt                                            */
    (uint32_t)&I2C3_EV_IRQHandler,              /* I2C3 event interrupt                                               */
    (uint32_t)&I2C3_ER_IRQHandler,              /* I2C3 error interrupt                                               */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    0,                                          /* Reserved                                                           */
    (uint32_t)&SPI4_IRQHandler,                 /* SPI 4 global interrupt                                             */
    (uint32_t)&SPI5_IRQHandler,                 /* SPI 5 global interrupt                                             */
};

void default_handler(void)
{
    while(1);
}

void Reset_Handler(void)
{
    // copy data from flash to ram
    uint32_t size = &_edata - &_sdata;
    uint32_t *p_sdata = (uint32_t*)&_sdata;
    uint32_t *p_sidata = (uint32_t*)&_sidata;

    for(uint32_t i = 0; i < size; i++) {
        *p_sdata = *p_sidata;
        p_sdata++;
        p_sidata++;    
    }

    uint32_t *p_sbss = (uint32_t*)&_sbss;
    size = &_ebss - &_sbss;
    for(uint32_t i = 0; i < size; i++) {
        *p_sbss = 0U;
        p_sbss++;
    }

    main();

    // Never return
    for(;;);
}

int _write(int fd, const char *ptr, int len)
{
    (void)fd;  // Ignore file descriptor, use ITM

    for(int i = 0; i < len; i++) {
        // will be implemented
    }

    return len;
}