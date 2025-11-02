#include "../include/advanced_array_function.h"
#include <malloc.h>

int max_subarray_sum(int* nums, int size)
{
    return 0;
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
