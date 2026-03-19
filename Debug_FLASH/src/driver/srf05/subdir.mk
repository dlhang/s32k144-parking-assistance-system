################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/srf05/srf05.c 

OBJS += \
./src/driver/srf05/srf05.o 

C_DEPS += \
./src/driver/srf05/srf05.d 


# Each subdirectory must supply rules for building sources it contributes
src/driver/srf05/%.o: ../src/driver/srf05/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/driver/srf05/srf05.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


