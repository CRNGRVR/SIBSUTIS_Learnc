#include <malloc.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char *word;
    int repetions;
} word;

int main(int argc, char **argv)
{
    char str[1024];
    fgets(str, 1024, stdin);
    word *words = (word*)calloc(1, sizeof(word));
    int wc = 0;

    //  Первая итерация, когда список ещё пустой
    char *new = strtok(str, ",");
    words = (word*)realloc(words, (wc + 1) * sizeof(word));
    words[wc].word = (char*)calloc(1, strlen(new) + 1);
    strcpy(words[wc].word, new);
    words[wc].repetions = 1;
    wc++;

    while (1)
    {
        new = strtok(NULL, ",");

        if (new == NULL)
        {
            break;
        }

        for (int i = 0; i < wc; i++)
        {
            if (strcmp(new, words[i].word) == 0)
            {
                words[i].repetions++;
                break;
            }

            if (i == wc - 1)
            {
                //  Последняя итерация, считается что нет слова в массиве такого же
                words = (word*)realloc(words, (wc + 1) * sizeof(word));
                words[wc].word = (char*)calloc(1, strlen(new) + 1);
                strcpy(words[wc].word, new);
                words[wc].repetions = 1;
                wc++;
                break;
            }
        }
    }


    for (int i = 0; i < wc; i++)
    {
        printf("%s %d \n", words[i].word, words[i].repetions);
    }
    
    for (int i = 0; i < wc; i++)
    {
        free(words[i].word);
    }

    free(words);
    

    return 0;
}
