#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../common/getcmdinput.h"
#define  COUNT 2

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите 2 числа.");
    if (numbers == NULL) return -1;

    int countNumbers = 0;

    //  Изначально считаем что число простое, пока не опровергнем это
    bool flag = true;

    //  numbers[0] - нижняя  граница диапазона
    //  numbers[1] - верхняя граница диапазона
    for (int i = numbers[0]; i < numbers[1]; i++)
    {
        //  Делить на  0 нельзя
        //  Деление на 1 всегда будет приносить true
        //  По этому с 2 начинаем
        int divider = 2;
        while (divider < i)
        {
            //  В цикле проверяем каждое число на деление всеми возможными
            //  делителями от 2 до самого числа не включительно
            if (i % divider == 0)
            {
                //  Число не простое
                flag = false;
                break;
            }

            divider++;
        }

        if (flag == false)
        {
            flag = true;
        }
        else
        {
            countNumbers++;
        }
    }
    
    printf("Простых чисел в диапазоне: %d\n", countNumbers);
    
    clearcmdinput(numbers);
    return 0;
}
    