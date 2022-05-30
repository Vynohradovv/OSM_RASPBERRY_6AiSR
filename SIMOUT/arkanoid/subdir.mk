################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arkanoid/arkanoid.cpp \
../arkanoid/guard.cpp \
../arkanoid/rectangle.cpp 

OBJS += \
./arkanoid/arkanoid.o \
./arkanoid/guard.o \
./arkanoid/rectangle.o 

CPP_DEPS += \
./arkanoid/arkanoid.d \
./arkanoid/guard.d \
./arkanoid/rectangle.d 


# Each subdirectory must supply rules for building sources it contributes
arkanoid/%.o: ../arkanoid/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	x86_64-linux-gnu-g++ -I"D:\Projects\PolitechnikaLodzka\ARosMiBase\arkanoid" -I"D:\Projects\PolitechnikaLodzka\ARosMiBase\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


