/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Hossam Eid
 * @brief          : An example on how to use the SVCall and its SVC number to
 * 				   : implement various operations.
 ******************************************************************************
 */

/*Try making mathematical operations using SVCall*/
int add(int x, int y)
{
    int result = 0;
    
    /*SVC number 0 for addition*/
    __asm("SVC 0x00");
    __asm("MOV %[out], PC"
         :[out] "=r" (result));

    return result;
}

int mul(int x, int y)
{
    int r = 0;

    /*SVC number 1 for multiplication*/
    __asm("SVC 0x01");
    __asm("MOV %[out], r3"
         :[out] "=r" (r));

    return r;
}

int sub(int x, int y)
{
    int result = 0;

    /*SVC number 2 for subtraction*/
    __asm("SVC 0x02");
    __asm("MOV %[out], r0"
         :[out] "=r" (result));

    return result;
}

void SVC_Handler_main(unsigned int* ptrStackStart)
{
    /*We will get the SVC number by getting the PC from the stack*/
    unsigned char svcNumber = ((char *)ptrStackStart[6])[-2];

    switch(svcNumber) 
    {
    case 0:
        /*
            Add the value that was in R0 and R1 and store the result in R0 place on the stack frame,
            Since we use R0 to return the value from the functions
        */
        ptrStackStart[0] = ptrStackStart[0] + ptrStackStart[1]; /*R0 = R0 + R1*/
        break;

    case 1:
        ptrStackStart[0] = ptrStackStart[0] * ptrStackStart[1]; /*R0 = R0 * R1*/
        break;

    case 2:
        ptrStackStart[0] = ptrStackStart[0] - ptrStackStart[1]; /*R0 = R0 - R1*/
        break;
    
    default:
        ptrStackStart[0] = ptrStackStart[0] + ptrStackStart[1]; /*R0 = R0 + R1*/
    }

    return;
}

/**
 * @brief ISR for the SVCall 
 * 
 * @note  This needs to be naked to tell the compiler this function will 
 * be entirely written an assembly, it also stops the compiler from generating
 * prologue and epilogue for the function.
 */
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

int main(void)
{
    int x, y, z;
    x = 10;
    y = 5;
    
    z = add(x, y);
    
    z = mul(x, y);
    
    z = sub(x, y);
    
    while(1)
    {

    }
}
