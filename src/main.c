// Copyright Benjamin Kyd 2021 All Rights Reserved

// PIN LAYOUT
// PIN 0-3 RED DAC
// PIN 4-7 GREEN DAC
// PIN 8-11 BLUE DAC
// PIN 12 HSYNC
// PIN 13 VSYNC

#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    setup_default_uart();
    printf("Hello, world!\n");
    return 0;
}
