################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/zlib/contrib/iostream3/test.cc \
../src/zlib/contrib/iostream3/zfstream.cc 

OBJS += \
./src/zlib/contrib/iostream3/test.o \
./src/zlib/contrib/iostream3/zfstream.o 

CC_DEPS += \
./src/zlib/contrib/iostream3/test.d \
./src/zlib/contrib/iostream3/zfstream.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/iostream3/%.o: ../src/zlib/contrib/iostream3/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


