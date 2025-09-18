#include <stdio.h>
#include <stdlib.h>
#include "../common/getcmdinput.h"
#define  COUNT 5

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите 5 чисел.");
    if (numbers == NULL) return -1;

    int summ = 0;
    for (int i = 0; i < COUNT; i++)
    {
        if (numbers[i] > 0)
        {
            summ += numbers[i];
        }
    }

    printf("Сумма положительных чисел: %d\n", summ);
    clearcmdinput(numbers);
    return 0;
}
