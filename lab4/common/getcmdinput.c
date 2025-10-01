#include <malloc.h>
#include <stdlib.h>

int *getcmdinput(int expected, int real, char **cmdInput,
                 const char *erroutput)
{
    // +1 потому что первый аргумент всегда название
    if (real != expected + 1)
    {
        printf("%s\n", erroutput);
        return NULL;
    }

    int *numbers = calloc(expected, sizeof(int));
    for (int i = 1; i < expected + 1; i++)
    {
        numbers[i - 1] = atoi(cmdInput[i]);
    }

    return numbers;
}

void clearcmdinput(int *numbers)
{
    free(numbers);
}
