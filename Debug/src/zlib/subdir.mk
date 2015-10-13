################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/zlib/adler32.o \
../src/zlib/compress.o \
../src/zlib/crc32.o \
../src/zlib/deflate.o \
../src/zlib/example.o \
../src/zlib/gzclose.o \
../src/zlib/gzlib.o \
../src/zlib/gzread.o \
../src/zlib/gzwrite.o \
../src/zlib/infback.o \
../src/zlib/inffast.o \
../src/zlib/inflate.o \
../src/zlib/inftrees.o \
../src/zlib/minigzip.o \
../src/zlib/trees.o \
../src/zlib/uncompr.o \
../src/zlib/zutil.o 

C_SRCS += \
../src/zlib/adler32.c \
../src/zlib/compress.c \
../src/zlib/crc32.c \
../src/zlib/deflate.c \
../src/zlib/gzclose.c \
../src/zlib/gzlib.c \
../src/zlib/gzread.c \
../src/zlib/gzwrite.c \
../src/zlib/infback.c \
../src/zlib/inffast.c \
../src/zlib/inflate.c \
../src/zlib/inftrees.c \
../src/zlib/trees.c \
../src/zlib/uncompr.c \
../src/zlib/zutil.c 

OBJS += \
./src/zlib/adler32.o \
./src/zlib/compress.o \
./src/zlib/crc32.o \
./src/zlib/deflate.o \
./src/zlib/gzclose.o \
./src/zlib/gzlib.o \
./src/zlib/gzread.o \
./src/zlib/gzwrite.o \
./src/zlib/infback.o \
./src/zlib/inffast.o \
./src/zlib/inflate.o \
./src/zlib/inftrees.o \
./src/zlib/trees.o \
./src/zlib/uncompr.o \
./src/zlib/zutil.o 

C_DEPS += \
./src/zlib/adler32.d \
./src/zlib/compress.d \
./src/zlib/crc32.d \
./src/zlib/deflate.d \
./src/zlib/gzclose.d \
./src/zlib/gzlib.d \
./src/zlib/gzread.d \
./src/zlib/gzwrite.d \
./src/zlib/infback.d \
./src/zlib/inffast.d \
./src/zlib/inflate.d \
./src/zlib/inftrees.d \
./src/zlib/trees.d \
./src/zlib/uncompr.d \
./src/zlib/zutil.d 


# Each subdirectory must supply rules for building sources it contributes
src/zlib/%.o: ../src/zlib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


