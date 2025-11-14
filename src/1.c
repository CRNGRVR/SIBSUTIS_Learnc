#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COLUMNS 10
#define LINES 20

int main(int argc, char **argv)
{
    srand(time(0));
    int a[COLUMNS][LINES] = {};

    //  Заполнение рандомными числами
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < LINES; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    printf("Оригинальная матрица:\n\n");
    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < LINES; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nИзменённая матрица:\n");

    int b[COLUMNS][LINES] = {};
    for (int i = 0; i < COLUMNS; i+=2)
    {
        for (int j = 0; j < LINES; j++)
        {
            b[i][j] = a[i + 1][j];
        }

        for (int j = 0; j < LINES; j++)
        {
            b[i + 1][j] = a[i][j];
        }   
    }

    for (int i = 0; i < COLUMNS; i++)
    {
        for (int j = 0; j < LINES; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
