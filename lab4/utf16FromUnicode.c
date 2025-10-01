#include <stdio.h>
#include "./common/getcmdinput.h"
#define COUNT 1

int main(int argc, char** argv)
{
    unsigned int unicode = 0;
    unsigned int utf16_result = 0;

    int *numbers = getcmdinput(COUNT, argc, argv, "Введите одно число.");
    if (numbers == NULL) return -1;
    unicode = numbers[0];
    clearcmdinput(numbers);
    
    if ((unicode > 0 && unicode <= 0xd7ff) || (unicode > 0xe000 && unicode <= 0xffff))
    {
        utf16_result = unicode;
    }
    else
    {
        unsigned int newcode = unicode - 0x10000;
        unsigned int big =    ((newcode & 0b11111111110000000000) >> 10) + 0xd800;
        unsigned int little = (newcode & 0b1111111111) + 0xdc00;

        utf16_result = little | (big << 16);
    }

    printf("%u\n", utf16_result);
    return 0;
}