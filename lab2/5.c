#include <stdio.h>
#include <stdlib.h>
#define  COUNT 4

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d чисел\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    short posOfMinimal = 0;

    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    int minimal = numbers[0];
    
    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] < minimal)
        {
            minimal = numbers[i];
            posOfMinimal = i;
        }
    }

    printf("Минимальное число %d в позиции %d(номер %d)\n", minimal,
           posOfMinimal, posOfMinimal + 1);
    return 0;
}   
