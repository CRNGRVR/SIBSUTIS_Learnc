#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

//  f(x)=(2x+lg x)/(1+lg x)
double *target_function(double h, int a, int b, int *arr_size)
{
    double *values = (double*)calloc(1, sizeof(double));

    int i = 0;
    for (double x = a; x < b; x += h)
    {
        values[i] = ( (2 * x) + log10(x) ) / ( 1 + log10(x) );
        i++;
        values = (double*)realloc(values, sizeof(double) * (i + 1));
    }

    *arr_size = i + 1;
    return values;
}

//  I1=h*(a[0]/2+a[1]+a[2]+…+a[N-1]+a[N]/2)
double integral_trapezoid(double *values, int val_size, double h)
{
    double result = 0;

    for (int i = 1; i < (val_size - 1); i++)
    {
        result += values[i];
    }

    result += (values[0] / 2);
    result += (values[val_size - 1] / 2);
    result *= h;

    return result;
}

//  I2=h/3*( a[0]+a[N] + 4*(a[1]+a[3]+…+a[N-1]) + 2*(a[2]+a[4]+…+a[N-2]))
double integral_simpson(double *values, int val_size, double h)
{
    double result = 0;

    //  Нечётные
    double nechet = 0;
    for (int i = 1; i < (val_size - 1); i++)
    {
        if (i % 2 != 0)
        {
            nechet += values[i];
        }
    }

    //  Чётные
    double chet = 0;
    for (int i = 2; i < (val_size - 2); i++)
    {
        if (i % 2 == 0)
        {
            chet += values[i];
        }
    }
    
    result = (h/3) * ( (values[0] + values[val_size - 1])
                       + (4 * nechet) + (2 * chet) );

    return result;
}

void clear_values(double *values)
{
    free(values);
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        printf("Usage: %s [n] [a] [b]\n", argv[0]);
        return -1;
    }

    int a = atoi(argv[2]);  //  Начало интервала
    int b = atoi(argv[3]);  //  Конец  интервала
    double h = ( (b - a) / atof(argv[1]));  //  Шаг

    int values_size;
    double *values = target_function(h, a, b, &values_size);
    double tr_integral = integral_trapezoid(values, values_size, h);
    double spsn_integral = integral_simpson(values, values_size, h);


    printf("Integral calculated via trapezoid:            %f,\n",
           tr_integral);

    printf("Integral calculated via The Simpson Method:   %f\n",
           spsn_integral);

    printf("Difference between methods:                   %f\n\n",
           fabs(tr_integral - spsn_integral));

    clear_values(values);
    return 0;
}
