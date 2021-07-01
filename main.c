// Copyright Benjamin Kyd 2021 All Rights Reserved

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

#include "pico/stdlib.h"

#include "vga.h"

// PIN LAYOUT
// PIN 0-3 RED DAC
// PIN 4-7 GREEN DAC
// PIN 8-11 BLUE DAC
// PIN 12 HSYNC
// PIN 13 VSYNC

int main()
{
    stdio_init_all();
    sleep_ms(1400);

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_LED_PIN, 1);

    printf("VGA Initalizing...\n");

    const video_timing_t video_timing = vga_timing_800x600_60;
    vga_init(&video_timing);

    while(true) 
    {
        tight_loop_contents();
    }
}
