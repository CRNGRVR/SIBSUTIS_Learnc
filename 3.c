#include <malloc.h>
#include <stdio.h>
#include <string.h>

void words_clear(char **words, int len)
{
    for (int i = 0; i < len; i++)
    {
        free(words[i]);
    }
    free(words);
}

int main(int argc, char **argv)
{
    char str[1024];
    fgets(str, 1024, stdin);
    char **words = (char**)calloc(1, sizeof(char**));

    //  Первая итерация, когда список ещё пустой
    char *new = strtok(str, ",");
    words[0] = (char*)calloc(1, strlen(new) + 1);
    strcpy(words[0], new);

    int iterator = 1;
    while (1)
    {
        new = strtok(NULL, ",");
        if (new == NULL) break;

        words = (char**)realloc(words, (iterator + 1) * sizeof(char*));
        words[iterator] = (char*)calloc(1, strlen(new) + 1);
        strcpy(words[iterator], new);

        iterator++;
    }

    printf("before sort: ");
    for (int i = 0; i < iterator; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");


    for (int i = 0; i < iterator; i++)
    {
        for (int j = 0; j < iterator; j++)
        {
            if (strcmp(words[i], words[j]) < 0)
            {
                char *tmp = words[i];
                words[i] = words[j];
                words[j] = tmp; 
            }
        }
    }


    printf("Sorted: ");
    for (int i = 0; i < iterator; i++)
    {
        printf("%s ", words[i]);
    }
    printf("\n");

    words_clear(words, iterator);
    return 0;
}
