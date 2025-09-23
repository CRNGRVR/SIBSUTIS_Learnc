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

    printBin(num);
    return 0;
}

