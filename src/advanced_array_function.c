#include "../include/advanced_array_function.h"
#include <malloc.h>
#include <limits.h>
#include <math.h>

char _is_all_negative(int *nums, int size)
{
    int negatives = 0;
    for (size_t i = 0; i < size; i++) if (nums[i] < 0) negatives++;
    if (negatives == size) return 1;
    else return 0;
}

int max_subarray_sum(int* nums, int size)
{
    if (nums == NULL) return 0;
    int max = INT_MIN;
    int limit = 1;

    
    if (_is_all_negative(nums, size))
    {
        //  Не все числа отрицательные
        for (size_t i = 0; i < size; i++)
        {
            int summ = 0;
            for (size_t j = i; j < size; j++)
            {
                summ += nums[j];
            }

            if (summ > max)
            {
                max = summ;
            }
        }

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i; j < size; j++)
            {
                int summ = 0;
                for (size_t k = i; k <= j; k++)
                {
                    summ += nums[k];
                    printf("%d ", nums[k]);
                }
                printf("\n");

                if (summ > max)
                {
                    max = summ;
                }
            }
        }
    }
    else
    {
        /// DEBUG
        for (size_t i = 0; i < size; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n\n");

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = i; j < size; j++)
            {
                int summ = 0;
                for (size_t k = i; k <= j; k++)
                {
                    summ += nums[k];
                    printf("%d ", nums[k]);
                }

                printf("\n");

                if (summ > max)
                {
                    max = summ;
                }
            }
        }
    }

    return max;
}



int length_of_lis(int* nums, int numsSize)
{
    if (nums == NULL) return 0;

    int numOfSequence = 0;
    int *lens = (int*)calloc(numOfSequence + 1, sizeof(int));
    if (lens == NULL) return -1;
    int next = nums[1];

    for (int i = 0; i < numsSize; i++)
    {
        //  Для последнего случая, когда num[i + 1] не существует
        if (i == numsSize - 1) 
        {
            lens[numOfSequence]++;
            break;
        }

        next = nums[i + 1];

        if (nums[i] < next)
        {
            lens[numOfSequence]++;
        }
        else
        {
            lens[numOfSequence]++;
            numOfSequence++;

            lens = (int*)realloc(lens, sizeof(int) * (numOfSequence + 1));
            lens[numOfSequence] = 0;
        }
    }

    int max = lens[0];
    for (int i = 0; i < numOfSequence; i++)
    {
        if (max < lens[i])
        {
            max = lens[i];
        }
    }

    free(lens);
    return max;
}

int* merge(int* intervals, int intervalsSize, int* returnSize)
{
    return NULL;
}
