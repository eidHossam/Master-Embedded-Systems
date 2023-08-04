
MEMORY
{
	flash(RX): o = 0x08000000, l = 128K
	sram (RWX): o = 0x20000000, l = 20k 
}

SECTIONS
{
	.vectors :
	{
		*.o(.vectors*)
	}> flash

	.text :
	{
		*.o(*.text)
	}> flash

	.rodata :
	{
		*.o(.rodata)
		_E_RODATA = .; 
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
		_S_BSS = .;
		*.o(.bss) *(COMMON)
		. = ALIGN(4);
		_E_BSS = .;
	}>sram

	. = . + 0x1000;
	_stack_top = .;
}