#include <stdio.h>
#include "./common/getcmdinput.h"
#define COUNT 1
#define FOUR_BYTES_MASK  0b11110000000000000000000000000000
#define THREE_BYTES_MASK 0b111000000000000000000000
#define TWO_BYTES_MASK   0b1100000000000000

int main(int argc, char** argv)
{
    unsigned int utf8_code = 0;
    unsigned int unicode_result = 0;

    int *numbers = getcmdinput(COUNT, argc, argv, "Введите одно число.");
    if (numbers == NULL) return -1;
    utf8_code = numbers[0];
    clearcmdinput(numbers);

    if ((utf8_code & FOUR_BYTES_MASK) == FOUR_BYTES_MASK)
    {
        //  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        unsigned int byte1 = (utf8_code & 0b00000111000000000000000000000000) >> 24;
        unsigned int byte2 = (utf8_code & 0b001111110000000000000000) >> 16;
        unsigned int byte3 = (utf8_code & 0b0011111100000000) >> 8;
        unsigned int byte4 = (utf8_code & 0b0011111111);

        unicode_result = byte4 | (byte3 << 6) | (byte2 << 12) | (byte1 << 18);
    }
    else if ((utf8_code & THREE_BYTES_MASK) == THREE_BYTES_MASK)
    {
        //  1110xxxx 10xxxxxx 10xxxxxx
        unsigned int byte1 = (utf8_code & 0b000011110000000000000000) >> 16;
        unsigned int byte2 = (utf8_code & 0b0011111100000000) >> 8;
        unsigned int byte3 = (utf8_code & 0b00111111);

        unicode_result = byte3 | (byte2 << 6) | (byte1 << 12);
    }
    else if ((utf8_code & TWO_BYTES_MASK) == TWO_BYTES_MASK)
    {
        //  110xxxxx 10xxxxxx
        unsigned int byte1 = (utf8_code & 0b0001111100000000) >> 8;
        unsigned int byte2 = (utf8_code & 0b00111111);

        //  Отступ 6 бит а не 8 потому что значения шестибитовые
        unicode_result = byte2 | (byte1 << 6);
    }
    else
    {
        unicode_result = utf8_code;
    }

    printf("%u\n", unicode_result);
    return 0;
}
