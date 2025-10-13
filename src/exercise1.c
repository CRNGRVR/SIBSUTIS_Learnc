#include <stdio.h>

int main(int argc, char** argv)
{
    float numbers[10] = {};
    scanf("%f %f %f %f %f %f %f %f %f %f", &numbers[0], &numbers[1], &numbers[2],
          &numbers[3], &numbers[4], &numbers[5], &numbers[6], &numbers[7],
          &numbers[8], &numbers[9]);

    float middle = 0;
    for (int i = 0; i < 10; i++)
    {
        middle += numbers[i];
    }

    middle /= 10;
    printf("%f\n", middle);
}