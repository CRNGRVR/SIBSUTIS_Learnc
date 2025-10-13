#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int numbers[10] = {};
    scanf("%d %d %d %d %d %d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2],
          &numbers[3], &numbers[4], &numbers[5], &numbers[6], &numbers[7],
          &numbers[8], &numbers[9]);


    int k = atoi(argv[1]);

    int buff = 0;
    int last = numbers[9];
    for (int i = 0; i < 9; i++)
    {
        buff = numbers[i + 1];
        numbers[i + 1] = numbers[i];
        numbers[i] = buff;
        //  2 3 4 5 6 7 8 9 10

        // buff = numbers[i - 1];
        // numbers[i - 1] = numbers[i];
        // numbers[i] = buff;
        //  2 3 4 5 6 7 8 1 9 
    }
    
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
}