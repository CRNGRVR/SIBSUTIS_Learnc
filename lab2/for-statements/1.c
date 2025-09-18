#include <stdio.h>
#include "../common/getcmdinput.h"
#define COUNT 2

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите два числа.");
    if (numbers == NULL) return -1;

    int summ = 0;
    for (int i = numbers[0]; i <= numbers[1]; i++)
    {
        summ+= i;
    }
    
    printf("Сумма чисел в заданном диапазоне(включительно): %d\n", summ);

    clearcmdinput(numbers);
    return 0;
}
