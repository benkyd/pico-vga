#include <stdio.h>
#include "pico/stdlib.h"

const uint OUTPIN = 1;

int main()
{
    stdio_init_all();

    gpio_init(OUTPIN);
    gpio_set_dir(OUTPIN, 1);

    while (1) 
    {

        printf("Hello, world!");
        gpio_put(OUTPIN, 1);

    }


    return 0;
}
