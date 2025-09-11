#include <stdio.h>
#include <stdlib.h>
#define  COUNT 6

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d чисел\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    int summ = 0;
    int multiplied = 1;

    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }
    
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
}
