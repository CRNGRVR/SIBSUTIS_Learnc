#include <stdio.h>
#include <stdlib.h>
#include "../common/getcmdinput.h"
#define  COUNT 4

int main(int argc, char** argv)
{
    int *numbers = getcmdinput(COUNT, argc, argv, "Введите 4 числа.");
    if (numbers == NULL) return -1;

    for (int i = 0; i < COUNT; i++)
    {
        for (int j = 0; j < COUNT; j++)
        {
            if (numbers[i] < numbers[j])
            {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
        
    }

    printf("Наибольшее: %d, наибольшее поменьше: %d\n", numbers[COUNT - 1],
           numbers[COUNT - 2]);
    clearcmdinput(numbers);
    return 0;
}   
