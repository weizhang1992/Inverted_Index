################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/zlib/contrib/inflate86/inffas86.c 

S_UPPER_SRCS += \
../src/zlib/contrib/inflate86/inffast.S 

OBJS += \
./src/zlib/contrib/inflate86/inffas86.o \
./src/zlib/contrib/inflate86/inffast.o 

C_DEPS += \
./src/zlib/contrib/inflate86/inffas86.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/inflate86/%.o: ../src/zlib/contrib/inflate86/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/zlib/contrib/inflate86/%.o: ../src/zlib/contrib/inflate86/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


