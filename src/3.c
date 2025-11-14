#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int main(int argc, char **argv)
{
    srand(time(0));
    int a[N][N] = {};

    //  Заполнение рандомными числами
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    printf("Оригинальная матрица:\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\nИзменённая матрица:\n");

    int b[N][N] = {};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            b[i][j] = a[j][i];
        } 
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
