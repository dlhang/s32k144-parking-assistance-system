################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/uart/uart.c 

OBJS += \
./src/driver/uart/uart.o 

C_DEPS += \
./src/driver/uart/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/driver/uart/%.o: ../src/driver/uart/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/driver/uart/uart.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


