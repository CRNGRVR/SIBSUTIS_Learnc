#include <stdio.h>
#include <math.h>
#include "../common/getcmdinput.h"
#define COUNT 2

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите два числа.");
    if (numbers == NULL) return -1;

    float result = 0;
    float multiplier = 0.18;
    for (int i = 1; i <= numbers[1]; i++)
    {
        result += pow((multiplier * numbers[0]), i);
        if (multiplier < 0.36) multiplier += 0.02;
    }

    printf("x = %d, n = %d, s = %.3f\n", numbers[0], numbers[1], result);

    clearcmdinput(numbers);
    return 0;
}
