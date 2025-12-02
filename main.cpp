#include <stdlib.h>
#include "./include/graphics.h"
#include <math.h>

#define COLOR(r,g,b) (r|(g<<8)|(b<<16)|15<<24)

#define OFFSET_X 100
#define OFFSET_Y 100

typedef struct {
    double x;
    double y;
} Point;

int main()
{
    Point points1[1000] = {};
    Point points2[1000] = {};

    for (int i = -500; i < 500; i++)
    {
        points1[i].x = i;
        points1[i].y = sqrt( (i - 3) );
    }
    
    for (int i = -500; i < 500; i++)
    {
        points2[i].x = i;
        points2[i].y = 16;
    }


    initwindow(640, 360);
    setcolor(BROWN);
    
    for (int i = -500; i < 500; i++)
    {
        putpixel(points1[i].x + OFFSET_X, points1[i].y + OFFSET_Y, BROWN);
    }

    for (int i = -500; i < 500; i++)
    {
        putpixel(points2[i].x + OFFSET_X, points2[i].y + OFFSET_Y, BROWN);
    }


    for (int i = 0; i < 100; i++)
    {
        putpixel(OFFSET_X + 50, (i + OFFSET_Y), BROWN);
    }
    
    floodfill(OFFSET_X + 50, 0, BROWN);
    outtextxy(OFFSET_X + 60, OFFSET_Y - 20, "FUNCTION F(x) = sqrt(x - 3)");
    outtextxy(OFFSET_X + 60, OFFSET_Y + 30, "FUNCTION F(x) = 16");

    getch();
    closegraph();
    return 0;
}