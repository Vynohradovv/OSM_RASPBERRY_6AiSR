################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../arkanoid/arkanoid.cpp \
../arkanoid/arkanoid_text.cpp \
../arkanoid/ball.cpp \
../arkanoid/blue_rec.cpp \
../arkanoid/green_rec.cpp \
../arkanoid/guard.cpp \
../arkanoid/purple_rec.cpp \
../arkanoid/rectangle.cpp \
../arkanoid/red_rec.cpp \
../arkanoid/yellow_rec.cpp 

OBJS += \
./arkanoid/arkanoid.o \
./arkanoid/arkanoid_text.o \
./arkanoid/ball.o \
./arkanoid/blue_rec.o \
./arkanoid/green_rec.o \
./arkanoid/guard.o \
./arkanoid/purple_rec.o \
./arkanoid/rectangle.o \
./arkanoid/red_rec.o \
./arkanoid/yellow_rec.o 

CPP_DEPS += \
./arkanoid/arkanoid.d \
./arkanoid/arkanoid_text.d \
./arkanoid/ball.d \
./arkanoid/blue_rec.d \
./arkanoid/green_rec.d \
./arkanoid/guard.d \
./arkanoid/purple_rec.d \
./arkanoid/rectangle.d \
./arkanoid/red_rec.d \
./arkanoid/yellow_rec.d 


# Each subdirectory must supply rules for building sources it contributes
arkanoid/%.o: ../arkanoid/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	x86_64-linux-gnu-g++ -I"D:\Projects\PolitechnikaLodzka\ARosMiBase\arkanoid" -I"D:\Projects\PolitechnikaLodzka\ARosMiBase\src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


