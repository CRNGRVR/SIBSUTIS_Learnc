#include <stdio.h>
#include "./common/getcmdinput.h"
#define  COUNT 3

int main(int argc, char** argv)
{
    int *number = getcmdinput(COUNT, argc, argv, "Введите три числа.\n");
    if (number == NULL) return -1;

    int r = number[0];
    int g = number[1];
    int b = number[2];
    clearcmdinput(number);

    /*
        0x00000000
          ^ ^ ^ ^
          | | | |__ R
          | | |____ G
          | |______ B
          |________ Non-used byte
    */
    int rgb = (r) | (g << 8) | (b << 16);

    printf("Упакованное число: %d\n", rgb);
    return 0;
}

