#include "pico/types.h"

typedef struct scanvideo_timing {
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
} scanvideo_timing_t;

const scanvideo_timing_t vga_timing_800x600_60 =
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
