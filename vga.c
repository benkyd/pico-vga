// Copyright Benjamin Kyd 2021 All Rights Reserver=d

#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/pwm.h"
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

void vga_init(const video_timing_t* timing)
{
    
    printf("Pixel Clock Frequency %i", timing->clock_freq);


}

