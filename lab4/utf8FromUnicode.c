#include <stdio.h>
#include "./common/getcmdinput.h"
#define COUNT 1

int main(int argc, char** argv)
{
    unsigned int unicode_code = 0;
    unsigned int utf8_result = 0;

    int *numbers = getcmdinput(COUNT, argc, argv, "Введите одно число.");
    if (numbers == NULL) return -1;
    unicode_code = numbers[0];
    clearcmdinput(numbers);
    
    if (unicode_code <= 0x7f)
    {
        //  xxxxxxxx
        utf8_result = unicode_code;
    }
    else if (unicode_code >= 0x80 && unicode_code <=0x7ff)
    {
        //  110xxxxx 10xxxxxx
        unsigned char rawbyte1 = (unicode_code & 0b11111000000) >> 6;
        unsigned char rawbyte2 = (unicode_code & 0b00000111111);
        
        unsigned char utfbyte1 = (0b11000000 | rawbyte1);
        unsigned char utfbyte2 = (0b10000000 | rawbyte2);
        
        utf8_result = (utfbyte1 << 8) | utfbyte2;
    }
    else if (unicode_code >= 0x800 && unicode_code <= 0xffff)
    {
        //  1110xxxx 10xxxxxx 10xxxxxx
        unsigned char rawbyte1 = (unicode_code & 0b1110000000000000) >> 12;
        unsigned char rawbyte2 = (unicode_code & 0b111111000000) >> 6;
        unsigned char rawbyte3 = (unicode_code & 0b111111);
        
        unsigned char utfbyte1 = (0b1110000000 | rawbyte1);
        unsigned char utfbyte2 = (0b1000000000 | rawbyte2);
        unsigned char utfbyte3 = (0b1000000000 | rawbyte3);

        utf8_result = ((utfbyte1 << 12) | (utfbyte2 << 6) | utfbyte3);
    }
    else if (unicode_code >= 10000 && unicode_code <= 0x1fffff)
    {
        //  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
        unsigned char rawbyte1 = (unicode_code & 0b111000000000000000000) >> 18;
        unsigned char rawbyte2 = (unicode_code & 0b111111000000000000) >> 12;
        unsigned char rawbyte3 = (unicode_code & 0b111111000000) >> 6;
        unsigned char rawbyte4 = (unicode_code & 0b111111);
        
        unsigned char utfbyte1 = (0b1111000000 | rawbyte1);
        unsigned char utfbyte2 = (0b1000000000 | rawbyte2);
        unsigned char utfbyte3 = (0b1000000000 | rawbyte3);
    }

    printf("%u\n", utf8_result);
    return 0;
}
