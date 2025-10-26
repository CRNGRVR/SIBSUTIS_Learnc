#include "../include/array_function.h"

void join_int_arrays(int *src1, size_t size_src1, int *src2, size_t size_src2,
                     int *dest)
{
    for (size_t i = 0; i < size_src1; i++)
    {
        dest[i] = src1[i];
    }

    for (size_t i = 0; i < size_src2; i++)
    {
        dest[i + size_src1] = src2[i];
    }
}

void join_and_sort_int_arrays(int* src1, size_t size_src1, int* src2,
                              size_t size_src2, int* dest)
{
    join_int_arrays(src1, size_src1, src2, size_src2, dest);

    for (int i = 0; i < size_src1 + size_src2; i++)
    {
        for (int j = 0; j < size_src1 + size_src2; j++)
        {
            if (dest[i] < dest[j])
            {
                int tmp = dest[i];
                dest[i] = dest[j];
                dest[j] = tmp;
            }
        }
    }
}

void get_min_and_max_from_int_array(int* src, size_t size, int* min, int* max)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (src[i] < src[j])
            {
                int tmp = src[i];
                src[i] = src[j];
                src[j] = tmp;
            }
        }
    }

    *min = src[0];
    *max = src[size - 1];
}

