#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Введите одно число.");
        return -1;
    }

    char *reversed = NULL;
    int iterator = 0;
    //  Вычисляем откуда начать чтение наоборот
    while (argv[1][iterator] != 0)
    {
        iterator++;
    }

    while (iterator >= 0)
    {
        printf("%c", argv[1][iterator]);
        iterator--;
    }
    
    printf("\n");
    return 0;
}
