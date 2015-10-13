################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/zlib/examples/enough.c \
../src/zlib/examples/fitblk.c \
../src/zlib/examples/gun.c \
../src/zlib/examples/gzappend.c \
../src/zlib/examples/gzjoin.c \
../src/zlib/examples/gzlog.c \
../src/zlib/examples/zpipe.c \
../src/zlib/examples/zran.c 

OBJS += \
./src/zlib/examples/enough.o \
./src/zlib/examples/fitblk.o \
./src/zlib/examples/gun.o \
./src/zlib/examples/gzappend.o \
./src/zlib/examples/gzjoin.o \
./src/zlib/examples/gzlog.o \
./src/zlib/examples/zpipe.o \
./src/zlib/examples/zran.o 

C_DEPS += \
./src/zlib/examples/enough.d \
./src/zlib/examples/fitblk.d \
./src/zlib/examples/gun.d \
./src/zlib/examples/gzappend.d \
./src/zlib/examples/gzjoin.d \
./src/zlib/examples/gzlog.d \
./src/zlib/examples/zpipe.d \
./src/zlib/examples/zran.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/examples/%.o: ../src/zlib/examples/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


