#include <stdlib.h>
#include "./include/graphics.h"
#include <math.h>
#include <windows.h>
#include <ctime>

#define COLOR(r,g,b) (r|(g<<8)|(b<<16)|15<<24)

typedef struct {
    double x;
    double y;
    int color;
} snowflake;

int main()
{
    srand(time(NULL));
    snowflake flakes[100] = {};
    initwindow(1500, 1500);

    while (1)
    {
        cleardevice();

        for (int i = 0; i < 100; i++)
        {
            flakes[i].x = rand() % 1500;
            flakes[i].y = rand() % 1500;
            flakes[i].color = rand() % 15;
        }

        for (int i = 0; i < 100; i++)
        {
            setcolor(flakes[i].color);
            setfillstyle(SOLID_FILL, flakes[i].color);
            fillellipse(flakes[i].x, flakes[i].y, 10, 10);
        }

        Sleep(100);
    }
    
    getch();
    closegraph();
    return 0;
}