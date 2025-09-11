#include <stdio.h>
#include <stdlib.h>
#define  COUNT 4

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

    //  Взял код с сортировкой из прошлого задания ввиду необходимости
    //  оптимизаци времени на разработку
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

    printf("Наибольшее: %d, наибольшее поменьше: %d\n", numbers[COUNT - 1],
           numbers[COUNT - 2]);
    return 0;
}   
