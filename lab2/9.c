#include <stdio.h>
#include <stdlib.h>
#define  COUNT 3

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d чисел\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    int min = numbers[0];
    int minPos = 0;
    int max = numbers[0];
    int maxPos = 0;

    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
            maxPos = i;
        }

        if (numbers[i] < min)
        {
            min = numbers[i];
            minPos = i;
        }
    }
    
    numbers[maxPos] = min;
    numbers[minPos] = max;

    printf("Результат: ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}
