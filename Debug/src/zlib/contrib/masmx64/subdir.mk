################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/zlib/contrib/masmx64/inffas8664.c 

ASM_SRCS += \
../src/zlib/contrib/masmx64/gvmat64.asm \
../src/zlib/contrib/masmx64/inffasx64.asm 

OBJS += \
./src/zlib/contrib/masmx64/gvmat64.o \
./src/zlib/contrib/masmx64/inffas8664.o \
./src/zlib/contrib/masmx64/inffasx64.o 

C_DEPS += \
./src/zlib/contrib/masmx64/inffas8664.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/masmx64/%.o: ../src/zlib/contrib/masmx64/%.asm
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/zlib/contrib/masmx64/%.o: ../src/zlib/contrib/masmx64/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


