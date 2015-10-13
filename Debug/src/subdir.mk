################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/getfilelist.cpp \
../src/gzip.cpp \
../src/invertindex.cpp \
../src/main.cpp \
../src/parser.cpp \
../src/table.cpp \
../src/tempindex.cpp 

OBJS += \
./src/getfilelist.o \
./src/gzip.o \
./src/invertindex.o \
./src/main.o \
./src/parser.o \
./src/table.o \
./src/tempindex.o 

CPP_DEPS += \
./src/getfilelist.d \
./src/gzip.d \
./src/invertindex.d \
./src/main.d \
./src/parser.d \
./src/table.d \
./src/tempindex.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


