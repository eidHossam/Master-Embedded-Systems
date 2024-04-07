# Lab to demonstrate how to change the ARM CPU access level.

## From Privileged access level to unprivileged and vice versa

    After reset, we worked on thread mode with privileged access level using the main stack.
![Reset](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/8df10ec3-41f2-4a09-b8cd-7d3463435e7c)


    Goto the unprivileged access level by write on CONTROL using MSR/MRS Instruction 
    to access special registers
![To_Unprivileged](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/5a75a77e-bf4a-4418-a7cd-54b138b64c88)



    trying to go back to privileged mode while still in thread mode will be denied
![Deny_Access](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/5d8313b0-4b99-4591-8325-58cb339f62c2)


    to go back to the privileged state, we must go into handler mode by generating an interrupt because the CONTROL needs privileged access level to use it.
![To_Privileged](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/4d59fcbc-f51b-4e05-bec8-67c6cd476e87)
![Privileged](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/02f00347-1c7a-4717-bb85-4ed9cfd5f39b)


    Whole Image
![image](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/be7c0e97-9700-42bc-91ce-1fef9d9417af)



## What happens if we use resource (NVIC) which needs a privileged access level while being in an unprivileged access state?
    It will generate a hard-fault interrupt and get stuck in it.
![HardFault](https://github.com/eidHossam/Master-Embedded-Systems/assets/106603484/cfe369a7-4449-4413-ad9f-40d2e2b24750)
