#include <stdio.h>
#include <math.h>

int main(void)
{
    float z = 3;
    float t = 2;
    float y = cos(t + z);
    float x = 4 * log(pow(y, 3)) - z / t;
    printf("%f\n", x);
}
