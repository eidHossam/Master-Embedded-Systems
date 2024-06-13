# ARM Cortex-M SVCall Example

### Overview

This project demonstrates how to handle Supervisor Calls (SVCall) on an ARM Cortex-M processor. It shows how to extract the SVC number and use it with arguments on the stack to perform various mathematical operations such as addition, multiplication, and subtraction.

## Program flow

1. You call one of the following operations to initiate the SVC exception:

    - **Addition Function** Performs addition using SVCall with SVC number 0.

    - **Multiplication Function** Performs multiplication using SVCall with SVC number 1.

    - **Subtraction Function** Performs subtraction using SVCall with SVC number 2.

2. Executing the SVC handler to get the stack address that was used for the stacking process

    ```c
    void __attribute__((naked)) SVC_Handler(void)
    {
    /*
        Our goal here is to find the starting address of the stack that was used for the exception
        entry stacking process.
    */
    /*1- Determine which stack was used based on the EXC_RETURN value in the LR*/
    __asm("TST LR, #0x4");
    __asm("ITE EQ");
    __asm("MRSEQ R0, MSP"); /*If bit 3 in the LR is set to 1 that means we used the main stack*/
    __asm("MRSNE R0, PSP"); /*If bit 3 in the LR is set to 0 that means we used the process stack*/

    /*2- After loading the stack address in R0 which is the register used to pass arguments between functions
         we will call a C function to handle the mathematical operations
    */
    __asm("B SVC_Handler_main");
    __asm(".ALIGN 4");
    }
    ```

    **Note**: This needs to be naked to tell the compiler this function will
    be entirely written an assembly, it also stops the compiler from generating
    prologue and epilogue for the function.

3. Then the **SVC_Handler_main** C function will be called with the stack start address as the argument

    Add the value that was in R0 and R1 and store the result in R0 place on the stack frame,
    Since we use R0 to return the value from the functions
