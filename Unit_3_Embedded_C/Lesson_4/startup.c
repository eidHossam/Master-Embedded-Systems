#include <stdint.h>

extern int main();
void Reset_Handler();
void Default_Handler();
void NMI_Handler()__attribute__((weak, alias("Default_Handler")));
void H_fault_Handler()__attribute__((weak, alias("Default_Handler")));
void MM_fault_Handler()__attribute__((weak, alias("Default_Handler")));
void data_to_ram();
void bss_init();


uint32_t stack_top[256];
void (* vectors[])()__attribute__((section(".vectors"))) = {
	(void (*)())((uint32_t)stack_top + sizeof(stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&MM_fault_Handler
};


extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;

void data_to_ram()
{
	uint32_t data_size = &_E_data - &_S_data;
	uint8_t *P_src = (uint8_t *)&_E_text;
	uint8_t *P_dst = (uint8_t *)&_S_data;
	int32_t i;

	for (i = 0; i < data_size; ++i)
		*((uint8_t *)P_dst++) = *((uint8_t *)P_src++);
}

void bss_init()
{
	uint32_t bss_size = &_E_bss - &_S_bss;
	uint8_t *P_dst = (uint8_t *)&_S_bss;
	int32_t i;

	for (i = 0; i < bss_size; ++i)
		*((uint8_t *)P_dst++) = (uint8_t)0;

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