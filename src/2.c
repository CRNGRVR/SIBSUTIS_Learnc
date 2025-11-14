#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(int argc, char **argv)
{
    srand(time(0));
    float a[N][N] = {};

    //  Заполнение рандомными числами
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = (float)(rand() % 10) + ( ((float)(rand() % 1000)) * 0.001 );
        }
    }

    printf("Оригинальная матрица:\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        float line_summ = 0;
        for (int j = 0; j < N; j++)
        {
            line_summ += a[i][j];
        }

        for (int j = 0; j < N; j++)
        {
            a[i][j] = a[i][j] / line_summ;
        }
    }

    printf("\nИзменённая матрица:\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
