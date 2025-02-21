#include "fb.h"
#include "io.h"
#include "multicore.h"

unsigned int R = 80;

void core0_main(void)
{
    while(R)
    {
        drawCircle(200, 150, R, 0x13, 1);
        drawString(190, 150, "Core 0", 0x0f, 2);
        R = R - 2;
        wait_msec(10000);
    }
}

void core1_main(void)
{
    clear_core1();                // Only run once
    while(R)
    {
        drawCircle(200, 330, R, 0x13, 1);
        drawString(190, 330, "Core 1", 0x0f, 2);
        R = R - 2;
        wait_msec(20000);
    }
}

void core2_main(void)
{
    clear_core2();                // Only run once
    while(R)
    {
        drawCircle(600, 150, R, 0x13, 1);
        drawString(590, 150, "Core 2", 0x0f, 2);
        R = R - 2;
        wait_msec(40000);
    }
}

void core3_main(void)
{
    clear_core3();                // Only run once
    while(R)
    {
        drawCircle(600, 330, R, 0x13, 1);
        drawString(590, 330, "Core 3", 0x0f, 2);
        R = R - 2;
        wait_msec(80000);
    }
}

void main(void)
{
    fb_init();
    drawRect(10, 10, 790, 470, 0x03, 0);

    start_core1(core1_main);      // Kick it off on core 1
    start_core2(core2_main);      // Kick it off on core 2
    start_core3(core3_main);      // Kick it off on core 2

    core0_main();                 // Loop endlessly
}