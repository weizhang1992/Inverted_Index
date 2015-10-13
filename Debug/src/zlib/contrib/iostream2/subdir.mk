################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/zlib/contrib/iostream2/zstream_test.cpp 

OBJS += \
./src/zlib/contrib/iostream2/zstream_test.o 

CPP_DEPS += \
./src/zlib/contrib/iostream2/zstream_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/iostream2/%.o: ../src/zlib/contrib/iostream2/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


