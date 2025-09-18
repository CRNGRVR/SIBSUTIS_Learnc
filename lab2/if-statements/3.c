#include <stdio.h>
#include <stdlib.h>
#include "../common/getcmdinput.h"
#define  COUNT 4

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите 4 числа.");
    if (numbers == NULL) return -1;

    printf("Введены числа:           ");

    int summ = 0;
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

    clearcmdinput(numbers);
    return 0;
}
