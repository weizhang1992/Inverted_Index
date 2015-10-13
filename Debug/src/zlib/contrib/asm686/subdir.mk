################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/zlib/contrib/asm686/match.S 

OBJS += \
./src/zlib/contrib/asm686/match.o 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/asm686/%.o: ../src/zlib/contrib/asm686/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


