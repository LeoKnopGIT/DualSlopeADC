################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../User/ch32v00x_it.c \
../User/display.c \
../User/init.c \
../User/main.c \
../User/system_ch32v00x.c 

C_DEPS += \
./User/ch32v00x_it.d \
./User/display.d \
./User/init.d \
./User/main.d \
./User/system_ch32v00x.d 

OBJS += \
./User/ch32v00x_it.o \
./User/display.o \
./User/init.o \
./User/main.o \
./User/system_ch32v00x.o 



# Each subdirectory must supply rules for building sources it contributes
User/%.o: ../User/%.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/Debug" -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/Core" -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/User" -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
