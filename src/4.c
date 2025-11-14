#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define N 3

int main(int argc, char **argv)
{
    srand(time(0));
    int a[N][N] = {};

    bool is_magic = false;
    int attempt = 0;
    while (is_magic != true)
    {
        is_magic = true;
        //  Заполнение рандомными числами
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                a[i][j] = rand() % 10;
            }
        }



        //  Проверка по строкам
        int summ = 0;
        for (int i = 0; i < N; i++)
        {
            summ += a[0][i];
        }

        for (int i = 1; i < N; i++)
        {
            int internal_summ = 0;
            for (int j = 0; j < N; j++)
            {
                internal_summ += a[i][j];
            }

            if (summ != internal_summ)
            {
                is_magic = false;
                break;
            }
        }
        
        //  Проверка строк
        for (int i = 0; i < N; i++)
        {
            int internal_summ = 0;
            for (int j = 0; j < N; j++)
            {
                internal_summ += a[j][i];
            }

            if (summ != internal_summ)
            {
                is_magic = false;
                break;
            }        
        }

        attempt++;
    }
    
    printf("Магия случилась на %d попытке: \n", attempt);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    return 0;
}
