################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/ch32v00x_adc.c \
../Peripheral/src/ch32v00x_dbgmcu.c \
../Peripheral/src/ch32v00x_dma.c \
../Peripheral/src/ch32v00x_exti.c \
../Peripheral/src/ch32v00x_flash.c \
../Peripheral/src/ch32v00x_gpio.c \
../Peripheral/src/ch32v00x_i2c.c \
../Peripheral/src/ch32v00x_iwdg.c \
../Peripheral/src/ch32v00x_misc.c \
../Peripheral/src/ch32v00x_opa.c \
../Peripheral/src/ch32v00x_pwr.c \
../Peripheral/src/ch32v00x_rcc.c \
../Peripheral/src/ch32v00x_spi.c \
../Peripheral/src/ch32v00x_tim.c \
../Peripheral/src/ch32v00x_usart.c \
../Peripheral/src/ch32v00x_wwdg.c 

C_DEPS += \
./Peripheral/src/ch32v00x_adc.d \
./Peripheral/src/ch32v00x_dbgmcu.d \
./Peripheral/src/ch32v00x_dma.d \
./Peripheral/src/ch32v00x_exti.d \
./Peripheral/src/ch32v00x_flash.d \
./Peripheral/src/ch32v00x_gpio.d \
./Peripheral/src/ch32v00x_i2c.d \
./Peripheral/src/ch32v00x_iwdg.d \
./Peripheral/src/ch32v00x_misc.d \
./Peripheral/src/ch32v00x_opa.d \
./Peripheral/src/ch32v00x_pwr.d \
./Peripheral/src/ch32v00x_rcc.d \
./Peripheral/src/ch32v00x_spi.d \
./Peripheral/src/ch32v00x_tim.d \
./Peripheral/src/ch32v00x_usart.d \
./Peripheral/src/ch32v00x_wwdg.d 

OBJS += \
./Peripheral/src/ch32v00x_adc.o \
./Peripheral/src/ch32v00x_dbgmcu.o \
./Peripheral/src/ch32v00x_dma.o \
./Peripheral/src/ch32v00x_exti.o \
./Peripheral/src/ch32v00x_flash.o \
./Peripheral/src/ch32v00x_gpio.o \
./Peripheral/src/ch32v00x_i2c.o \
./Peripheral/src/ch32v00x_iwdg.o \
./Peripheral/src/ch32v00x_misc.o \
./Peripheral/src/ch32v00x_opa.o \
./Peripheral/src/ch32v00x_pwr.o \
./Peripheral/src/ch32v00x_rcc.o \
./Peripheral/src/ch32v00x_spi.o \
./Peripheral/src/ch32v00x_tim.o \
./Peripheral/src/ch32v00x_usart.o \
./Peripheral/src/ch32v00x_wwdg.o 



# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/%.o: ../Peripheral/src/%.c
	@	riscv-none-embed-gcc -march=rv32ecxw -mabi=ilp32e -msmall-data-limit=0 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/Debug" -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/Core" -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/User" -I"c:/Users/elokn/Documents/Studium_Master/DualSlopeADC/Software/CH32V003F4P6/Peripheral/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
