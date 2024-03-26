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

## Conclusion
This lab provides a hands-on exercise to understand how to integrate ARM inline assembly with C code. By following the provided instructions, participants can practice writing assembly instructions to perform arithmetic operations and manipulate data stored in C variables.