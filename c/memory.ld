ENTRY(Reset_Handler)

/* Memory Regions */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x08000000, LENGTH = 512K
    RAM (rwx)   : ORIGIN = 0x20000000, LENGTH = 128K
}

_start_of_stack = ORIGIN(RAM) + LENGTH(RAM);

/*
 * SECTIONS
 * Define the memory layout for the application.
 */
SECTIONS
{
    .text :
    {
        . = ALIGN(4);
        LONG(_start_of_stack) /* Initial Stack Pointer */
        /* ISR Vector Table - must be at address 0x08000000 */
        KEEP(*(.vector_table_sec))
        /* Collect all .text sections from input files */
        *(.text)
        *(.text.*)
        . = ALIGN(4);
    } > FLASH

    .rodata :
    {
        . = ALIGN(4);
        /* Collect all .rodata sections from input files */
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(4);
    } > FLASH

    /* Initialized data section, located in FLASH but copied to RAM at startup */
    .data :
    {
        _sidata = LOADADDR(.data); /* Start address of .data in FLASH (LMA)*/
        . = ALIGN(4);
        _sdata = .;  /* Start address of .data in RAM (VMA) */ 
        /* Collect all .data sections from input files */
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .; /* End address of .data in RAM */
    } > RAM AT> FLASH

    .bss :
    {
        . = ALIGN(4);
        _sbss = .;  /* Start address of .bss */
        __bss_start__ = _sbss;  /* Alias for libc */
        /* Collect all .bss sections from input files */
        *(.bss)
        *(.bss.*)
        . = ALIGN(4);
        _ebss = .;  /* End address of .bss */
        __bss_end__ = _ebss;    /* Alias for libc */
    } > RAM

    /* Heap starts after BSS - needed by _sbrk for malloc */
    end = .;
    _end = .;
}