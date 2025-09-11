#include <stdio.h>
#include <stdlib.h>
#define  COUNT 4

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d числa\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    int summ = 0;

    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    printf("Введены числа:           ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] < 0) numbers[i] = 0;
    }
    
    printf("Модифицированный массив: ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
