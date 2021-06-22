#include <stdio.h>
#include "pico/stdlib.h"

#include "hardware/pio.h"

// "assembled program"
#include "video.pio.h"

#include "vga.h"

int main()
{
    PIO pio = pio0;

    uint prog = pio_add_program(pio, &video_program);

    uint sm = pio_claim_unused_sm(pio, 1);

    video_program_init(pio, sm, progoffset, PICO_DEFAULT_LED_PIN);

    while (true) {
        // Blink
        pio_sm_put_blocking(pio, sm, 1);
        sleep_ms(500);
        // Blonk
        pio_sm_put_blocking(pio, sm, 0);
        sleep_ms(500);
    }


    return 0;
}
