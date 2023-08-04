/**
 * @file startup.c
 * 
 * @brief this file is the startup code for the 
 * cortex-M3 processor 
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 03-08-2023
 * 
 * @version 1.0
 */
#include <stdint.h>

/*ISR declarations*/
extern int main();
void Reset_Handler();
void Default_Handler();
void NMI_Handler()__attribute((weak, alias("Default_Handler")));
void H_Fault_Handler()__attribute((weak, alias("Default_Handler")));
void MM_Fault_Handler()__attribute((weak, alias("Default_Handler")));
void Bus_Fault_Handler()__attribute((weak, alias("Default_Handler")));

/*Declare the stack top defined in the linker script*/
extern uint32_t _stack_top;

/*Making the vector table while putting the stack top as the first element
for it to be initialized by the processor*/
void (* vectors[]) () __attribute__((section(".vectors"))) = 
{
    (void (*)())(&_stack_top),
    Reset_Handler,
    NMI_Handler,
    H_Fault_Handler,
    MM_Fault_Handler,
    Bus_Fault_Handler
};

/*Symbols from the linker script used to initialize 
the data and bss sections in the rams*/
extern uint32_t _E_RODATA;
extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;

void data_to_ram()
{
    uint32_t data_size = (uint8_t *)(&_E_DATA) - (uint8_t *)(&_S_DATA);
    uint8_t *Psrc = (uint8_t *)(&_E_RODATA);
    uint8_t *Pdest = (uint8_t *)(&_S_DATA);

    uint32_t i;
    for (i = 0; i < data_size; i++)
    {
        *((uint8_t *) Pdest++) = *((uint8_t *) Psrc++);
    }
}

void bss_init()
{
    uint32_t bss_size = (uint8_t *)(&_E_BSS) - (uint8_t *)(&_S_BSS);
    uint8_t *Pdest = (uint8_t *)(&_S_BSS);

    uint32_t i;
    for (i = 0; i < bss_size; i++)
    {
        *((uint8_t *) Pdest++) = (uint8_t)0;
    }
}

void Reset_Handler()
{
    data_to_ram();
    bss_init();

    main();
}

void Default_Handler()
{
    Reset_Handler();
}
