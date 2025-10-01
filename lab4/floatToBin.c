#include <stdio.h>
#include <stdlib.h>
#include "./common/getcmdinput.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Введите одно число.\n");
        return -1;
    }
   
    float number = atof(argv[1]);

    int integer = (int)number;
    float fractional = number - integer;
    
    return 0;
}