cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

# Pull in Raspberry Pi Pico SDK (must be before project)
set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

include_directories(${CMAKE_SOURCE_DIR})

project(pico_vga C CXX ASM)
pico_sdk_init()


# pico_generate_pio_header(pico_vga ${CMAKE_CURRENT_LIST_DIR}/video.pio)

add_executable(pico_vga
    src/main.c
    )

# Add the standard library to the build
target_link_libraries(pico_vga
    pico_stdlib
    # hardware_pio
    # hardware_dma
    # hardware_irq
    )

pico_add_extra_outputs(pico_vga)
