cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# initalize pico_sdk from installed location
# (note this can come from environment, CMake cache etc)
set(PICO_SDK_PATH "/home/ben/pico/pico-sdk")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(pico_vga C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

add_executable(pico_vga)

pico_set_program_name(pico_vga "pico_vga")
pico_set_program_version(pico_vga "0.1")

pico_enable_stdio_uart(pico_vga 1)
pico_enable_stdio_usb(pico_vga 1)

pico_generate_pio_header(pico_vga ${CMAKE_CURRENT_LIST_DIR}/video.pio)

target_sources(pico_vga PRIVATE picovga.c)

# Add the standard library to the build
target_link_libraries(pico_vga 
    pico_stdlib 
    hardware_pio
    )

pico_add_extra_outputs(pico_vga)

