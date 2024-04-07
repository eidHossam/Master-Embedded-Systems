# Lab to demonstrate how to change the ARM CPU access level.

## From Privileged access level to unprivileged and vice versa

    After reset, we worked on thread mode with privileged access level using the main stack.
![image]()

    Goto the unprivileged access level by write on CONTROL using MSR/MRS Instruction 
    to access special registers
![image]()

    trying to go back to privileged mode while still in thread mode will be denied
![image]()

    to go back to the privileged state, we must go into handler mode by generating an interrupt because the CONTROL needs privileged access level to use it.
![image]() 

    Whole Image
![image]() 


## What happens if we use resource (NVIC) which needs a privileged access level while being in an unprivileged access state?
    It will generate a hard-fault interrupt and get stuck in it.
![image]()  