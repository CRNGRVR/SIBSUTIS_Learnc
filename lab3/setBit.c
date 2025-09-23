#include <stdio.h>
#include "./common/getcmdinput.h"
#define  COUNT 2

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
    int *number = getcmdinput(COUNT, argc, argv, "Введите два числа.\n");
    if (number == NULL) return -1;

    int num = number[0];
    int oldnum = number[0];
    int pos = number[1];
    clearcmdinput(number);

    printf("Число %d в бинарном виде: \n", num);
    printBin(num);
    printf("\n");

    int mask = 1;
    mask = mask << pos;
    num = num | mask;

    printf("Маска: \n");
    printBin(mask);
    printf("\n");

    printf("Изменённое число %d -> %d теперь выглядит так:\n", oldnum, num);
    printBin(num);

    return 0;
}
