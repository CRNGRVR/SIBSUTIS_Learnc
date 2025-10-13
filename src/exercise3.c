#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    float numbers[10] = {};
    scanf("%f %f %f %f %f %f %f %f %f %f", &numbers[0], &numbers[1], &numbers[2],
          &numbers[3], &numbers[4], &numbers[5], &numbers[6], &numbers[7],
          &numbers[8], &numbers[9]);

    int k = atoi(argv[1]);
    
    if (k < 0)
    {
        for (int i = 0; i < abs(k); i++)
        {
            float buf = numbers[0];
            for (size_t i = 0; i < 9; i++)
            {
                numbers[i] = numbers[i + 1];
            }
            numbers[9] = buf;
        }
    }
    else if (k > 0)
    {
        for (int i = 0; i < abs(k); i++)
        {
            float buf = numbers[9];
            for (int j = 9; j > 0; j--)
            {
                numbers[j] = numbers[j - 1];
            }
            numbers[0] = buf;
        }
    }

    
    for (int i = 0; i <= 9; i++)
    {
        printf("%f ", numbers[i]);
    }
}