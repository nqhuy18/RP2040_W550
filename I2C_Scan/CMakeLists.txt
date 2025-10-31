cmake_minimum_required(VERSION 3.12)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(I2C_Scan C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# Creates a pico-sdk subdirectory in our project for the libraries
pico_sdk_init()


add_executable(${PROJECT_NAME} 
        main.c
        )

# pull in common dependencies and additional i2c hardware support
target_link_libraries(${PROJECT_NAME}  pico_stdlib hardware_i2c)

# create map/bin/hex file etc.
pico_add_extra_outputs(${PROJECT_NAME} )


# Enable usb output, disable uart output
pico_enable_stdio_usb(${PROJECT_NAME} 0)
pico_enable_stdio_uart(${PROJECT_NAME} 1)