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
    float z = 6;
    float t = 0.5;
    float y = t + (2 * ctg(z));
    float x = (3 * pow(y, 2)) / (4 * tg(z) - 2 * pow(t, 2));

    printf("%f\n", x);
}

