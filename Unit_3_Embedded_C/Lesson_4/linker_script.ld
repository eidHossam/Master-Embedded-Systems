

MEMORY
{
	flash (RX): ORIGIN = 0x00000000, LENGTH = 512M   
	sram (RWX): ORIGIN = 0x20000000, LENGTH = 512M	  
}

SECTIONS
{
	.text :
	{
		*.o(.vectors)
		*.o(.text)
		*.o(.rodata)
		_E_text = .;
	}> flash

	.data :
	{
		_S_data = .;
		*.o(.data)
		_E_data = .;
	}> sram AT> flash

	.bss :
	{
		_S_bss = .;
		*(.bss) *(COMMON)
		_E_bss = .;
	}> sram
}