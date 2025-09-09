#include <stdio.h>
#include <math.h>
#define EULER_CONST 2.71828

int main(void)
{
    float z = 3;
    float t = 1;
    float y = sin(t);
    float x = (4 * pow(y, 2)) / (4 * y * pow(EULER_CONST, (z * t)) - 2 * pow(t, 3));

    printf("%f\n", x);
}
