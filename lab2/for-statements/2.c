#include <stdio.h>
#include "../common/getcmdinput.h"
#define COUNT 1

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите одно число.");
    if (numbers == NULL) return -1;

    int fact = 1;
    for (int i = 1; i <= numbers[0]; i++)
    {
        fact *= i;
    }
    
    printf("%d! = %d\n", numbers[0], fact);

    clearcmdinput(numbers);
    return 0;
}
