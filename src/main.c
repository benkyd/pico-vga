// Copyright Benjamin Kyd 2021 All Rights Reserved

// PIN LAYOUT
// PIN 0-3 RED DAC
// PIN 4-7 GREEN DAC
// PIN 8-11 BLUE DAC
// PIN 12 HSYNC
// PIN 13 VSYNC

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "hardware/dma.h"
#include "hardware/irq.h"

#include "vga.pio.h"

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

static inline void vga_program_init(PIO pio, uint sm, uint offset, uint pin) {

    pio_gpio_init(pio, pin);
    pio_gpio_init(pio, pin+1);
    pio_sm_set_consecutive_pindirs(pio, sm, pin, 2, true);

    pio_sm_config c = vga_program_get_default_config(offset);

    sm_config_set_out_pins(&c, pin, 2);

    sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_TX);
    sm_config_set_out_shift(&c, false, true, 2);

    pio_sm_init(pio, sm, offset, &c);
    pio_sm_set_enabled(pio, sm, true);
}

int main() {
    PIO pio = pio0;
    uint offset = pio_add_program(pio, &vga_program);
    uint sm = pio_claim_unused_sm(pio, true);

    vga_program_init(pio, sm, offset, 12);

    while (true) {
        pio_sm_put_blocking(pio, sm, 0b01);
        sleep_ms(20);
        pio_sm_put_blocking(pio, sm, 0b10);
        sleep_ms(20);
    }
}
