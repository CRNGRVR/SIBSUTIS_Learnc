#include <stdio.h>
#include <stdlib.h>
#define  COUNT 3

int main(int argc, char** argv)
{
    if (argc != COUNT + 1)
    {
        printf("Введите %d чисел\n", COUNT);
        return -1;
    }

    int numbers[COUNT] = {};
    for (int i = 1; i < COUNT + 1; i++)
    {
        numbers[i - 1] = atoi(argv[i]);
    }

    
    for (int i = 0; i < COUNT; i++)
    {
        for (int j = 0; j < COUNT; j++)
        {
            if (numbers[i] < numbers[j])
            {
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
        
    }

    int k = numbers[0];
    int m = numbers[1];
    int n = numbers[2];

    printf("K=%d M=%d N=%d\n", k, m, n);
    return 0;
}   
