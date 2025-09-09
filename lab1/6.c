#include <stdio.h>
#include <math.h>
#define EULER_CONST 2.71828

double tg(double num)
{
    return sin(num) / cos(num);
}

int main(void)
{
    float z = 1;
    float t = 2;
    float y = tg(t) + z;
    float x = (8 * pow(z, 2) + 1) / (y * pow(EULER_CONST, t) + pow(t, 2));

    printf("%f\n", x);
}
