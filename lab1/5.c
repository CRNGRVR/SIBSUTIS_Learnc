#include <stdio.h>
#include <math.h>

double tg(double num)
{
    return sin(num) / cos(num);
}

double ctg(double num)
{
    return cos(num) / sin(num);
}

int main(void)
{
    float z = 4;
    float y = 2;
    float t = sin(2 + z);

    float x = 6 * pow(t, 2) - ((ctg(z) + 1) / pow(y, 2));

    printf("%f\n", x);
}
