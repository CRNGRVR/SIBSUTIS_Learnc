#include <stdio.h>
#include "./common/getcmdinput.h"
#define  COUNT 1

int main(int argc, char** argv)
{
    int *number = getcmdinput(COUNT, argc, argv, "Введите одно число.\n");
    if (number == NULL) return -1;

    int num = number[0];
    clearcmdinput(number);

    int r = 0;
    int g = 0;
    int b = 0;

    /*
        0x00000000
          ^ ^ ^ ^
          | | | |__ R
          | | |____ G
          | |______ B
          |________ Non-used byte
    */
    int mask = 0x000000FF;
    r = num & mask;
    g = (num & (mask <<  8)) >> 8;
    b = (num & (mask << 16)) >> 16;

    printf("R: %d, G: %d, B: %d\n", r, g, b);
    return 0;
}

