#include <stdio.h>
#include <stdlib.h>
#include "../common/getcmdinput.h"
#define  COUNT 6

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите 6 чисел.");
    if (numbers == NULL) return -1;

    int summ = 0;
    int multiplied = 1;
    for (int i = 0; i < COUNT; i++)
    {
        summ += numbers[i];
        multiplied *= numbers[i];
    }

    if (summ > multiplied)
    {
        printf("Сумма больше произведения на %d\n", summ - multiplied);
    }
    else if (summ < multiplied)
    {
        printf("Произведение больше суммы на %d\n", multiplied - summ);
    }
    else
    {
        printf("Сумма и произведение равны.\n");
    }

    clearcmdinput(numbers);
    return 0;
}
