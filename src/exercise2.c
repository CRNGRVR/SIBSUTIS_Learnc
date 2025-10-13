#include <stdio.h>

int main(int argc, char** argv)
{
    int numbers[10] = {};
    scanf("%d %d %d %d %d %d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2],
          &numbers[3], &numbers[4], &numbers[5], &numbers[6], &numbers[7],
          &numbers[8], &numbers[9]);

    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", numbers[i]);
    }

    printf("\n");
}