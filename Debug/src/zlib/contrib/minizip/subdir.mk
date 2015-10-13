################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/zlib/contrib/minizip/ioapi.c \
../src/zlib/contrib/minizip/iowin32.c \
../src/zlib/contrib/minizip/miniunz.c \
../src/zlib/contrib/minizip/minizip.c \
../src/zlib/contrib/minizip/mztools.c \
../src/zlib/contrib/minizip/unzip.c \
../src/zlib/contrib/minizip/zip.c 

OBJS += \
./src/zlib/contrib/minizip/ioapi.o \
./src/zlib/contrib/minizip/iowin32.o \
./src/zlib/contrib/minizip/miniunz.o \
./src/zlib/contrib/minizip/minizip.o \
./src/zlib/contrib/minizip/mztools.o \
./src/zlib/contrib/minizip/unzip.o \
./src/zlib/contrib/minizip/zip.o 

C_DEPS += \
./src/zlib/contrib/minizip/ioapi.d \
./src/zlib/contrib/minizip/iowin32.d \
./src/zlib/contrib/minizip/miniunz.d \
./src/zlib/contrib/minizip/minizip.d \
./src/zlib/contrib/minizip/mztools.d \
./src/zlib/contrib/minizip/unzip.d \
./src/zlib/contrib/minizip/zip.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/contrib/minizip/%.o: ../src/zlib/contrib/minizip/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


