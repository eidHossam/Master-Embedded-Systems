#include <stdint.h>

extern int main();
void Reset_Handler(void);
void Default_Handler(void);
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_fault(void) __attribute__((weak, alias("Default_Handler")));
void Usage_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void bss_init();
void data_to_ram();

extern int _stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) =
{
   (uint32_t)&_stack_top,
   (uint32_t)&Reset_Handler,
   (uint32_t)&NMI_Handler,
   (uint32_t)&H_fault_Handler,
   (uint32_t)&MM_fault_Handler,
   (uint32_t)&Bus_fault,
   (uint32_t)&Usage_fault_Handler,
};

extern int _E_text;
extern int _S_DATA;
extern int _E_DATA;
extern int _S_bss;
extern int _E_bss;

void bss_init()
{
   uint32_t data_size = (uint8_t *)&_E_bss - (uint8_t *)&_S_bss;
   uint8_t  *P_dst    = (uint8_t *)&_S_bss;

   for (int i = 0; i < data_size; ++i)
   {
      *((uint8_t *)P_dst++) = 0;
   }
}


void data_to_ram()
{
   uint32_t data_size  = (uint8_t *)&_E_DATA - (uint8_t *)&_S_DATA;
   uint8_t  *pData_src = (uint8_t *)&_E_text;
   uint8_t  *P_dst     = (uint8_t *)&_S_DATA;

   for (int i = 0; i < data_size; ++i)
   {
      *((uint8_t *)P_dst++) = *((uint8_t *)pData_src++);
   }
}


void Reset_Handler(void)
{
   data_to_ram();
   bss_init();
   main();
}


void Default_Handler(void)
{
   Reset_Handler();
}
