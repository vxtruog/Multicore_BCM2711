#include "io.h"
#include "fb.h"

void main()
{
    uart_init();
    fb_init();

    drawRect(10,10,790,470,0x03,0);
    drawRect(30,30,50,50,0x2e,1);

    drawCircle(300,300,120,0x0e,0);
    drawCircle(300,300,80,0x13,1);

    drawPixel(300,300,0x0e);

    drawChar('O',500,500,0x05);
    drawString(100,400,"Hello world!",0x0f);

    drawLine(400,200,600,120,0x0c);

    while (1);
}