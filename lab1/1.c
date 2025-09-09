#include <stdio.h>
#include <math.h>

int main(void)
{
    float y = 2;
    float z = 4;
    float t = 5 / (1 + pow((double)y, (double)2));
    float x = (2 * y) + (3 * sinh(t) - z);

    printf("%f\n", x);
}
