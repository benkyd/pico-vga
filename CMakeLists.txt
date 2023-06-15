cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Pull in Raspberry Pi Pico SDK (must be before project)
set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

project(pico_vga C CXX ASM)

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Werror")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")

pico_sdk_init()

add_executable(pico_vga
    src/main.c
    )

# Add the standard library to the build
target_link_libraries(pico_vga
    pico_stdlib
    hardware_pio
    hardware_dma
    hardware_irq
    )

pico_generate_pio_header(pico_vga ${CMAKE_CURRENT_LIST_DIR}/src/vga.pio)

pico_add_extra_outputs(pico_vga)
