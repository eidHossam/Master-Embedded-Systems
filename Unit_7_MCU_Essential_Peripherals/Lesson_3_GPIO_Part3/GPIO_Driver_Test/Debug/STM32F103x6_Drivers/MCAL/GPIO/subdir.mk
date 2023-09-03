################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F103x6_Drivers/MCAL/GPIO/stm32f103x6_GPIO.c 

OBJS += \
./STM32F103x6_Drivers/MCAL/GPIO/stm32f103x6_GPIO.o 

C_DEPS += \
./STM32F103x6_Drivers/MCAL/GPIO/stm32f103x6_GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F103x6_Drivers/MCAL/GPIO/stm32f103x6_GPIO.o: ../STM32F103x6_Drivers/MCAL/GPIO/stm32f103x6_GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I"D:/Learn-In-Depth/Unit_3/STMCUBE_WORKSPACE/Drivers_Test/STM32F103x6_Drivers/MCAL" -I"D:/Learn-In-Depth/Unit_3/STMCUBE_WORKSPACE/Drivers_Test/STM32F103x6_Drivers/MCAL/inc" -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"STM32F103x6_Drivers/MCAL/GPIO/stm32f103x6_GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

