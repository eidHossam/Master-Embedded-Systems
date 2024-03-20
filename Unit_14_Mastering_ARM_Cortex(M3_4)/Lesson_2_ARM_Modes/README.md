# ARM CPU modes Lab: 

- This lab aims to show the different ARM CPU modes and elaborate on when each mode is used.

## Operating Modes
1. **Thread mode** : The normal operating mode in which all the user processes are running, It's the default operating mode after the CPU comes out of the reset state.

2. **Handler mode** : The CPU enters this mode when an interrupt is detected and it goes to serve this interrupt.

## Operating states
1. **Thumb state** : This state indicates that the CPU is currently executing the instructions given to it.

2. **Debug state** : This state indicates that the CPU is halted by a debugger.

## Access Level
1. **Privileged access level** : In this state the software has access to all the resources of the system and has the ability to use all the instruction (This is the default access level).

2. **Unprivileged access level** : In this state the software is restricted from using the special instructions like (MRS, MSR), The software can't use all the system peripherals like (SYSTICK, NVIC, Control Block).

## CPU stack
- The SP register (R13) in the cortex-m3/4 is a shadow register that contain the value of 2 separate stack registers:
    1. MSP (Main Stack Pointer): This is the **default** stack used after reset, In-case of an OS It's advised to use this stack while running in the kernel space.
    2. PSP (Process Stack Pointer):  In-case of an OS It's advised to use this stack with the user-level programs.

## Flow of states
- When the CPU gets power or after pressing the reset button the CPU loads the R13 (SP) which initialy points to the main stack pointer with the value @address 0x00000000.

**note: The process of initializing the SP allows us to write our startup code in C instead of assmebly**

- Then the CPU loads the address of the Reset_Handler found @address 0x00000004 into the (R15) PC to start the initialization process found in the Reset_Handler ISR which makes the CPU run in **Thread_Mode with Privileged access level**.

- So the default mode after coming out of the reset state is the **Thread_Mode** with **Privileged access level** while using the **MSP**, The access level should be changed to **Unprivileged** before giving the CPU to any user processes, But in this lab we won't change the access level.


## 1. Executing the main function


#### While running in the main function we can see that as we previously said we are running in the thread mode with privileged access and using the MSP as we didn't change either of them.


## 2. Executing the EXTI line_9 ISR


#### After getting an external interrupt using th GPIOB_PIN9 the operating mode was switched from the thread mode to the handler mode to indicate that we are currently running an ISR, The number of the ISR being executed can be seen in IPSR (Interrupt Program Status Register) in the ISR bits.