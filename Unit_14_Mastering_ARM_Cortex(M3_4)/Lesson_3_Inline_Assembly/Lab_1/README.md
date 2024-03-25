# ARM Assembly Code for Simple Practice Lab

This document provides an explanation of the ARM assembly code that demonstrates how to convert a simple C code into ARM assembly. The code includes functions for subtraction and termination.

## C code

![Screenshot 2024-03-25 224256](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/05c95102-f89c-41c5-a255-2661e878d2d2)

## Assembly 
```
reset
		;Do the reset sequence and initialize 
		;the global data
		MOV		R1, #5
		;Jump to the main
		BL		main
		
		
main
		BL		subtract
		BL		terminate
		
subtract
		sub		R1, R1, #1
		CMP		R1, #0
		BNE		subtract
		mov		PC, LR
		
		
terminate
```

## Simulation


https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/69857d67-80f6-47a8-a69a-bea975b9cbc9

