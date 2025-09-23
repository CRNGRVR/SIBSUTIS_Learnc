#include <stdio.h>
#include "./common/getcmdinput.h"
#define  COUNT 1

void printBin(int num)
{
    for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
    {
        int num = num >> i;
        printf("%d", num & 1);
    }

    printf("\n");
}

int main(int argc, char** argv)
{
    int *number = getcmdinput(COUNT, argc, argv, "Введите одно число.\n");
    if (number == NULL) return -1;

    int num = number[0];
    clearcmdinput(number);

    printf("Число %d в бинарном виде: \n", num);
    printBin(num);
    printf("\n");

    int counter = 0;
    int mask = 1;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        counter += ((num & (mask << i)) >> i);
    }
    
    printf("Сумма бит в положении 1: %d\n", counter);

    return 0;
}

