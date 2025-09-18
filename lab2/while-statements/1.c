#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int summ = 0;
    int iterator = 0;
    while (argv[1][iterator] != 0)
    {
        //  atoi требует нуль-терминированную строку
        char nullTerminatedString[2] = {};
        nullTerminatedString[0] = argv[1][iterator];
        nullTerminatedString[1] = 0;

        summ += atoi(nullTerminatedString);
        iterator++;
    }
    
    printf("Сумма цифр числа: %d\n", summ);
    return 0;
}
