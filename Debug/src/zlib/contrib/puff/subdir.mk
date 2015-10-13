################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/zlib/contrib/puff/puff.c \
../src/zlib/contrib/puff/pufftest.c 

OBJS += \
./src/zlib/contrib/puff/puff.o \
./src/zlib/contrib/puff/pufftest.o 

C_DEPS += \
./src/zlib/contrib/puff/puff.d \
./src/zlib/contrib/puff/pufftest.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/puff/%.o: ../src/zlib/contrib/puff/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


