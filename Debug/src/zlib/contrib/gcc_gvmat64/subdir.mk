################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/zlib/contrib/gcc_gvmat64/gvmat64.S 

OBJS += \
./src/zlib/contrib/gcc_gvmat64/gvmat64.o 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/gcc_gvmat64/%.o: ../src/zlib/contrib/gcc_gvmat64/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


