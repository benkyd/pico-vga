// Copyright Benjamin Kyd 2021 All Rights Reserved

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

#include "vga.h"
#include "video.pio.h"

const video_timing_t vga_timing_800x600_60 =
{
        .clock_freq = 38400000,

        .h_active = 800,
        .v_active = 600,

        .h_front_porch = 4 * 8,
        .h_pulse = 10 * 8,
        .h_total = 128 * 8,
        .h_sync_polarity = 0,

        .v_front_porch = 1,
        .v_pulse = 3,
        .v_total = 625,
        .v_sync_polarity = 0,

        .enable_clock = 0,
        .clock_polarity = 0,

        .enable_den = 0
};

#define PIN_START 8
#define PIN_COUNT 2

void vga_init(const video_timing_t* timing)
{
    // Calculate the PIO clock divider
    uint sys_clock = frequency_count_khz(CLOCKS_FC0_SRC_VALUE_CLK_SYS);
    float clock_div = ((float)sys_clock * 1000.f) / (float)timing->clock_freq;

    printf("System clock frequency %i\n", sys_clock);
    printf("Pixel clock frequency %i\n", timing->clock_freq);
    printf("Clock divider %f\n", clock_div);
 


    // setup 2 buffers with DMA
    // setup swap
    
    // use pin mask (5 pins for 1 bit colour, 12 for 4)



}

