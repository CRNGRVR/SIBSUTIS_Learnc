#include <stdio.h>
#include <stdbool.h>
#include "../common/getcmdinput.h"
#define COUNT 1

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите 1 число.");
    if (numbers == NULL) return -1;

    int divider = 2;
    bool flag = true;   //  Число простое
    while (divider < numbers[0])
    {
        if (numbers[0] % divider == 0)
        {
            printf("Число сложное.\n");
            flag = false;
            break;
        }
        divider++;
    }

    if(flag)
    {
        printf("Число простое.\n");
    }
    
    clearcmdinput(numbers);
    return 0;
}
