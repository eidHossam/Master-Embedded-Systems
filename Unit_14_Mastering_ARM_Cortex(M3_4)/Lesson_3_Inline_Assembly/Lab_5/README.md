# ARM Inline Assembly Practice Lab Documentation

This lab provides a simple exercise to practice writing ARM inline assembly in C code. The objective is to take two operands from variables stored in C code, add them using assembly language, and store the result back in a variable in C code.

## Description

The provided C code contains two integer variables `operand1` and `operand2` with values 7 and 3 respectively. The `main` function contains ARM inline assembly instructions to add these operands and store the result in the `result` variable.

## Code Breakdown

### Variables Initialization
```c
int result = 0;
int operand1 = 7;
int operand2 = 3;
```
- result: Variable to store the result of the addition operation.
- operand1 and operand2: Variables storing the two operands.

```
__asm("add %[out], %[in1], %[in2]"
      :[out] "=r" (result)        // Output: result variable
      :[in1] "r" (operand1),      // Input: operand1 variable
       [in2] "r" (operand2)       // Input: operand2 variable
      : "r2");                     // Reserved register
```
- The add instruction adds the values of operand1 and operand2 and stores the result in result.
- Constraints [out] "=r" (- result), [in1] "r" (operand1), and [in2] "r" (operand2) specify the operands and their registers.
- The last column : "r2" res- erves register R2, preventing it from being used by the compiler.

## Program flow
![Load_Operand1_Address](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/6e2d44c7-48b4-44c9-bb45-11af7eeb68af)

![Load_Operand1_Value](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/811e0618-2665-4219-b8f2-577b966c8f5e)

![Load_Operand2_Value](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/7bc87c28-6837-4846-9e6c-929684d4a815)

![Add_Values](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/db10bcb7-ef8a-4a91-904d-693d9365b40c)

![Load_Result_Address](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/0c51b442-d3e7-4e70-a17c-b41e205ed44f)

![Store_Value_in_Result](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/f8377dc7-f3df-4251-9110-f2e9c2160b55)


## Conclusion
This lab provides a hands-on exercise to understand how to integrate ARM inline assembly with C code. By following the provided instructions, participants can practice writing assembly instructions to perform arithmetic operations and manipulate data stored in C variables.
