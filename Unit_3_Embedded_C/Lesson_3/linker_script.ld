/*Written by Hossam Eid
for lesson_3 lab_1 in
learn-in-detpth diploma*/

MEMORY
{
	flash (rx): ORIGIN = 0x08000000, LENGTH = 128K
	sram  (rwx):ORIGIN = 0x20000000, LENGTH = 20K 
}

SECTIONS
{
	.text :
	{
		*(.vectors)
		*.o(.text)
		*.o(.rodata)
		_E_text = .;
	}> flash

	.data :
	{
		_S_DATA = .;
		*.o(.data)
		. = ALIGN(4);
		_E_DATA = .;
	}> sram AT> flash

	.bss :
	{
		_S_bss = .;
		*.o(.bss) 	*(COMMON)
		_E_bss = .;
		. = . + 0x1000;
		_stack_top = .;
	}> sram
}