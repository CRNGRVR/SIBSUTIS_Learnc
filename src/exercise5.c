#include <stdio.h>

int main(int argc, char** argv)
{
    float A[10][3] = {};
    float B[3][10] = {};
    float result[10][10] = {};

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%f ", &A[i][j]);
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            scanf("%f ", &B[i][j]);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                result[i][j] += A[i][k] * B[k][j];
            }
            
            printf("%.2f", result[i][j]);
            //  Чтобы тест проходил
            if (i != 9 && j != 9) printf(" ");  
        }
    }
    
    return 0;
}