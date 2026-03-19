################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/driver/ftm_ic/ftm_ic.c 

OBJS += \
./src/driver/ftm_ic/ftm_ic.o 

C_DEPS += \
./src/driver/ftm_ic/ftm_ic.d 


# Each subdirectory must supply rules for building sources it contributes
src/driver/ftm_ic/%.o: ../src/driver/ftm_ic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Standard S32DS C Compiler'
	arm-none-eabi-gcc "@src/driver/ftm_ic/ftm_ic.args" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


