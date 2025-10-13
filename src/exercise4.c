#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    float numbers[10] = {};
    scanf("%f %f %f %f %f %f %f %f %f %f", &numbers[0], &numbers[1], &numbers[2],
          &numbers[3], &numbers[4], &numbers[5], &numbers[6], &numbers[7],
          &numbers[8], &numbers[9]);

    float x = atof(argv[1]);
    int k = atoi(argv[2]);
    
    for (int i = 9; i > k; i--)
    {
        numbers[i] = numbers[i - 1];
    }

    numbers[k] = x;

    for (int i = 0; i <= 9; i++)
    {
        printf("%f ", numbers[i]);
    }
}
