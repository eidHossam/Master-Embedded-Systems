/*Written by Hossam Eid
for lesson_3 lab_1 in
learn-in-detpth diploma*/

ENTRY(_reset)

MEMORY
{
	flash (rx): ORIGIN = 0x08000000, LENGTH = 128K
	sram  (rwx):ORIGIN = 0x20000000, LENGTH = 20K 
}

SECTIONS
{
	.text :
	{
		*(*.vectors)
		*.o(*.text)
	}> flash

	.rodata :
	{
		*.o(*.rodata)
	}> flash

	.data :
	{
		*.o(*.data)
	}>sram AT> flash

	.bss :
	{
		*.o(*.bss) 	*(COMMON)
	}> sram
}