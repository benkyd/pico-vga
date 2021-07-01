#include <stdio.h>

#include "pico/stdlib.h"

#include "vga.h"

int main()
{
    stdio_init_all();
    // Wait for stdio to initialize
    sleep_ms(100);

    printf("VGA Initalizing...\n");

    const video_timing_t video_timing = vga_timing_800x600_60;
    vga_init(&video_timing);

    

    while(true) 
    {
        tight_loop_contents();
    }
}
