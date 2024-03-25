# ARM Assembly Code for Simple Practice Lab

This document provides an explanation of the ARM assembly code that demonstrates how to convert a simple C code into ARM assembly. The code includes functions for subtraction and termination.

## C code


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
