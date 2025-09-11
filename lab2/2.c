#include <stdio.h>
#include <stdlib.h>
#define  COUNT 5

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d чисел\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    int summ = 0;

    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }
    
    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] > 0)
        {
            summ += numbers[i];
        }
    }

    printf("Сумма положительных чисел: %d\n", summ);
    return 0;
}
