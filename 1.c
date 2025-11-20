#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define PREDICATE argv[1]

int main(int argc, char **argv)
{
    char str[1024];
    fgets(str, 1024, stdin);
    
    int length_predicate = strlen(PREDICATE);

    char *new = strtok(str, ",");
    while (1)
    {
        if (new == NULL)
        {
            break;
        }

        if (strncmp(new, PREDICATE, length_predicate) == 0)
        {
            puts(new);
        }

        new = strtok(NULL, ",");
    }

    return 0;
}
