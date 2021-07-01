#ifndef PICOVGA_VGA_H_
#define PICOVGA_VGA_H_

#include "pico/types.h"

typedef struct video_timing {
    uint32_t clock_freq;

    uint16_t h_active;
    uint16_t v_active;

    uint16_t h_front_porch;
    uint16_t h_pulse;
    uint16_t h_total;
    uint8_t h_sync_polarity;

    uint16_t v_front_porch;
    uint16_t v_pulse;
    uint16_t v_total;
    uint8_t v_sync_polarity;

    uint8_t enable_clock;
    uint8_t clock_polarity;

    uint8_t enable_den;
} video_timing_t;

const video_timing_t vga_timing_800x600_60;

// typedef struct video {
//     uint16_t* 
// } video_t;

void vga_init(const video_timing_t* timing);

void vga_start();

void vga_swap_buffers();

#endif
