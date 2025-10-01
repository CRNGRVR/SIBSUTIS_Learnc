#include <stdio.h>
#include "./common/getcmdinput.h"
#define COUNT 1

int main(int argc, char** argv)
{
    unsigned int unicode_result = 0;
    unsigned int utf16 = 0;

    int *numbers = getcmdinput(COUNT, argc, argv, "Введите одно число.");
    if (numbers == NULL) return -1;
    utf16 = numbers[0];
    clearcmdinput(numbers);
    
    if (utf16 <= 0xFFFF)
    {
        unicode_result = utf16;
    }
    else
    {
        unsigned int big = (utf16 & 0b11111111111111110000000000000000) >> 16;
        unsigned int little = utf16 & 0b1111111111111111;

        if (big >= 0xD800 && big <= 0xDBFF && little >= 0xDC00 && little <= 0xDFFF)
        {
            big -= 0xD800;
            little -= 0xDC00;
        }

        unicode_result = (big << 10) | little;
        unicode_result += 0x10000;
    }

    printf("%u\n", unicode_result);
    return 0;
}