#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <ctime>
#include "./include/graphics.h"

#define BORDER_X_LEFT      0
#define BORDER_X_RIGHT  1500
#define BORDER_Y_TOP       0
#define BORDER_Y_BOTTOM 1500

#define KEY_ESC           27

#define STEP              10

#define FREEMOVE_UP        0
#define FREEMOVE_DOWN      1
#define FREEMOVE_LEFT      2
#define FREEMOVE_RIGHT     3

void draw_picture(int x, int y)
{
    cleardevice();
    setcolor(BLUE);
    circle(x, y, 50);
    line(x - 50, y - 50, x + 50, y + 50);
    line(x + 50, y - 50, x - 50, y + 50);
}

void draw_menu()
{
    cleardevice();
    setcolor(WHITE);
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(100, 100, (char*)"Hello, there it is a \"Calculation-graphical-task\", variation #8");
    outtextxy(100, 150, (char*)"Press [ 1 ] for entering the Free Move Mode,");
    outtextxy(100, 200, (char*)"          [ 2 ] for trying to direct a picture via keyboard,");
    outtextxy(100, 250, (char*)"          [ 3 ] for leaving this.");
}

//  Функция движения картинки клавишами [ e ] [ s ] [ d ] [ x ]
void keybord_mode()
{
    int x = 500;
    int y = 200;

    while (1)
    {
        draw_picture(x, y);
        char input = getch();
        switch (input)
        {
            //  Вверх
            case 'e':
            {
                if (y > BORDER_Y_TOP + 50)
                {
                    y -= STEP;
                }
                break;
            }
            //  Вниз
            case 'x':
            {
                if (y < BORDER_Y_BOTTOM - 50)
                {
                    y += STEP;
                }
                break;
            }
            //  Влево
            case 's':
            {
                if (x > BORDER_X_LEFT + 50)
                {
                    x -= STEP;
                }
                break;
            }
            //  Вправо
            case 'd':
            {
                if (x < BORDER_X_RIGHT - 50)
                {
                    x += STEP;
                }
                break;
            }
            case KEY_ESC:
            {
                return;
            }

            default: break;
        }
    }
}

//  Функция свободного движения картинки, вариант 2
void free_move()
{
    int x = 500;
    int y = 200;
    int direction = 0;
    int current_tact = 0;
    int tacts_to_change = 0;

    direction = rand() % 4;
    tacts_to_change = rand() % 50;

    while (1)
    {
        draw_picture(x, y);
        if (current_tact < tacts_to_change)
        {
            switch (direction)
            {
                case FREEMOVE_UP:
                {
                    if (y > BORDER_Y_TOP + 50)
                    {
                        //  Штатное движение
                        y -= STEP;
                    }
                    else
                    {
                        //  Отражение
                        direction = FREEMOVE_DOWN;
                    }
                    break;
                }

                case FREEMOVE_DOWN:
                {
                    if (y < BORDER_Y_BOTTOM - 50)
                    {
                        y += STEP;
                    }
                    else
                    {
                        direction = FREEMOVE_UP;
                    }
                    break;
                }

                case FREEMOVE_LEFT:
                {
                    if (x > BORDER_X_LEFT + 50)
                    {
                        x -= STEP;
                    }
                    else
                    {
                        direction = FREEMOVE_RIGHT;
                    }
                    break;
                }

                case FREEMOVE_RIGHT:
                {
                    if (x < BORDER_X_RIGHT - 50)
                    {
                        x += STEP;
                    }
                    else
                    {
                        direction = FREEMOVE_LEFT;
                    }
                    break;
                }

                default: break;
            }

            current_tact++;
        }
        else
        {
            current_tact = 0;
            tacts_to_change = rand() % 50;
            direction = rand() % 4;
        }

        //  Выход
        if (kbhit())
        {
            int key = getch();
            if (key == KEY_ESC)
            {
                return;
            }
        }

        Sleep(10);
    }
}

int main()
{
    srand(time(NULL));
    initwindow(BORDER_X_RIGHT, BORDER_Y_BOTTOM);

    while (1)
    {
        draw_menu();
        char input = getch();
        switch (input)
        {
            case '1':
                free_move();
                break;

            case '2':
                keybord_mode();
                break;

            case '3':
                closegraph();
                return 0;

            default: break;
        }
    }
}