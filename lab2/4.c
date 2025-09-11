#include <stdio.h>
#include <stdlib.h>
#define  COUNT 8

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d чисел\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    short positive = 0;
    short negative = 0;

    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }
    
    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] >= 0)
        {
            positive++;
        }
        else
        {
            negative++;
        }
    }

    printf("Положительных: %d, отрицательных: %d\n", positive, negative);
    return 0;
}
