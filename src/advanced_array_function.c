#include "../include/advanced_array_function.h"
#include <malloc.h>
#include <limits.h>
#include <math.h>
#define START_INTERVAL j
#define END_INTERVAL j + 1

char _is_all_negative(int *nums, int size)
{
    int negatives = 0;
    for (int i = 0; i < size; i++) if (nums[i] < 0) negatives++;
    if (negatives == size) return 1;
    else return 0;
}

int max_subarray_sum(int* nums, int size)
{
    if (nums == NULL) return 0;
    int max = INT_MIN;
    
    if (_is_all_negative(nums, size))
    {
        //  Не все числа отрицательные
        for (int i = 0; i < size; i++)
        {
            int summ = 0;
            for (int j = i; j < size; j++)
            {
                summ += nums[j];
            }

            if (summ > max)
            {
                max = summ;
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                int summ = 0;
                for (int k = i; k <= j; k++)
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
        for (int i = 0; i < size; i++)
        {
            printf("%d ", nums[i]);
        }
        printf("\n\n");

        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                int summ = 0;
                for (int k = i; k <= j; k++)
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


typedef struct interval
{
    int start;
    int end;
    struct interval *next;
} interval;

void _delete_interval_element(interval **list, interval* element)
{
    interval *tmp = *list;
    interval *previous = NULL;
    while (*list != NULL)
    {
        if (*list == element)
        {
            if (previous != NULL)
            {
                previous->next = (*list)->next;
                *list = tmp;
            }
            else
            {
                (*list) = (*list)->next;
            }

            free(element);
            break;
        }

        previous = *list;
        *list = (*list)->next;
    }
}

int* merge(int* intervals, int intervalsSize, int* returnSize)
{
    if (intervals == NULL) return 0;
    interval *base = (interval*)calloc(1, sizeof(interval));
    base->next = NULL;

    int *merged_intervals = (int*)calloc(2, sizeof(int));
    int merged_size = 0;

    //  Сортировка в связи с требованиями
    for (int i = 0; i < intervalsSize * 2; i += 2)
    {
        for (int j = 0; j < intervalsSize * 2; j += 2)
        {
            if (intervals[i] < intervals[j])
            {
                int tmp = intervals[i];
                int tmp1 = intervals[i + 1];

                intervals[i] = intervals[j];
                intervals[i + 1] = intervals[j + 1];

                intervals[j] = tmp;
                intervals[j + 1] = tmp1;
            }
        }
    }

    //  Заполнение
    interval *tmp = base;
    tmp->start = intervals[0];
    tmp->end = intervals[1];
    for (int i = 2; i < (intervalsSize * 2); i += 2)
    {   
        tmp->next = (interval*)calloc(1, sizeof(interval));
        tmp = tmp->next;
        tmp->start = intervals[i];
        tmp->end = intervals[i + 1];
    }
    tmp->next = NULL;

    interval *reviewed = base;
    interval *candidate = base;

    /**
    *  Для наглядности:
    * 
    *  Целевой интервал:   1, 4    1, 4
    *  Случай 1:          -1, 3   -1, 4
    *  Случай 2:           2, 5    1, 5
    *  Случай 3:           2, 3    1, 4
    *  Случай 4:          -1, 5   -1, 5
    */
    while (reviewed != NULL)
    {
        while (candidate != NULL && reviewed != NULL)
        {
            ///  NOTE: Когда значения интервалов candidate и reviewed равны,
            ///  условие >= работает как == и такой интервал удаляется не будучи в слиянии
            ///  Для удаления слияние обязательно, таков замысел
            if (candidate->start != reviewed->start && candidate->end != reviewed->end)
            {
                //  #1
                if (candidate->start <= reviewed->start && candidate->end <= reviewed->end &&
                    candidate->end >= reviewed->start)
                {
                    // candidate->start = reviewed->start;
                    reviewed->start = candidate->start;
                    //  Убрать блок забыл
                    // _delete_interval_element(&base, reviewed);
                    _delete_interval_element(&base, candidate);

                    reviewed = base;
                    candidate = base;
                    continue;
                }
                //  #2
                else if (candidate->start >= reviewed->start && candidate->end >= reviewed->end &&
                        candidate->start <= reviewed->end)
                {
                    //candidate->end = reviewed->end;
                    reviewed->end = candidate->end;
                    //  Убрать блок забыл
                    // _delete_interval_element(&base, reviewed);
                    _delete_interval_element(&base, candidate);
    
                    reviewed = base;
                    candidate = base;
                    continue;
                }
                //  #3
                // else if (intervals[START_INTERVAL] > start && intervals[END_INTERVAL] < end)
                // {
                //     continue;
                // }
                else if (candidate->start >= reviewed->start && candidate->end <= reviewed->end)
                {
                        //  candidate поглощается
                    _delete_interval_element(&base, candidate);

                    reviewed = base;
                    candidate = base;
                    continue;
                }
                //  #4
                else if (candidate->start <= reviewed->start && candidate->end >= reviewed->end)
                {
                    reviewed->end = candidate->end;
                    reviewed->start = candidate->start;
                    
                    //  Убрать блок забыл
                    _delete_interval_element(&base, candidate);

                    reviewed = base;
                    candidate = base;
                    continue;
                }
            }

            candidate = candidate->next;
        }

        reviewed = reviewed->next;
    }
        
        
    interval *printed = base;
    while (printed != NULL)
    {
        printf("%d %d  ", printed->start, printed->end);
        printed = printed->next;
    }

    int iterator = 0;
    while (base != NULL)
    {
        merged_intervals[iterator] = base->start;
        merged_intervals[iterator + 1] = base->end;
        merged_size++;
        
        merged_intervals = (int*)realloc(merged_intervals, ((sizeof(int) * (merged_size * 2) + 2)));
        iterator += 2;
        
        base = base->next;
    }
    
    *returnSize = merged_size;
    return merged_intervals;
}



// int* merge(int* intervals, int intervalsSize, int* returnSize)
// {
//     if (intervals == NULL) return 0;
//     int *src_intervals = (int*)calloc(2, sizeof(int));
//     int *merged_intervals = (int*)calloc(2, sizeof(int));
//     int merged_size = 0;

//     for (int i = 0; i < (intervalsSize * 2); i += 2)
//     {
//         src_intervals[i] = intervals[i];
//         src_intervals[i + 1] = intervals[i + 1];
//     }


//     for (int i = 0; i < (intervalsSize * 2); i += 2)
//     {
//         int start = src_intervals[i];
//         int end = src_intervals[i + 1];

//         /**
//          *  Для наглядности:
//          * 
//          *  Целевой интервал:   1, 4    1, 4
//          *  Случай 1:          -1, 3   -1, 4
//          *  Случай 2:           2, 5    1, 5
//          *  Случай 3:           2, 3    1, 4
//          *  Случай 4:          -1, 5   -1, 5
//          */
//         for (int j = 0; j < (intervalsSize * 2); j += 2)
//         {
//             //  #1
//             if (src_intervals[START_INTERVAL] < start && src_intervals[END_INTERVAL] < end &&
//                 src_intervals[END_INTERVAL] > start)
//             {
//                 start = src_intervals[START_INTERVAL];
//             }
//             //  #2
//             else if (src_intervals[START_INTERVAL] > start && src_intervals[END_INTERVAL] > end &&
//                      src_intervals[START_INTERVAL] < end)
//             {
//                 end = src_intervals[END_INTERVAL];
//             }
//             //  #3
//             else if (src_intervals[START_INTERVAL] > start && src_intervals[END_INTERVAL] < end)
//             {
//                 continue;
//             }
//             //  #4
//             else if (src_intervals[START_INTERVAL] < start && src_intervals[END_INTERVAL] > end)
//             {
//                 end = src_intervals[END_INTERVAL];
//                 start = src_intervals[START_INTERVAL];
//             }
//             else if (src_intervals[START_INTERVAL] == start && src_intervals[END_INTERVAL] == end)
//             {
//                 continue;
//             }
//             else
//             {
//                 continue;
//             }
//         }

//         merged_intervals = (int*)realloc(merged_intervals, sizeof(int) * ((i + 1) * 2));
//         merged_intervals[i /*START_INTERVAL*/ ] = start;
//         merged_intervals[i + 1 /*END_INTERVAL*/ ] = end;
//         merged_size++;
//     }

//     // for (int i = 0; i < (intervalsSize * 2); i += 2)
//     // {
//     //     int start = intervals[i];
//     //     int end = intervals[i + 1];

//     //     /**
//     //      *  Для наглядности:
//     //      * 
//     //      *  Целевой интервал:   1, 4    1, 4
//     //      *  Случай 1:          -1, 3   -1, 4
//     //      *  Случай 2:           2, 5    1, 5
//     //      *  Случай 3:           2, 3    1, 4
//     //      *  Случай 4:          -1, 5   -1, 5
//     //      */
//     //     for (int j = 0; j < (intervalsSize * 2); j += 2)
//     //     {
//     //         //  #1
//     //         if (intervals[START_INTERVAL] < start && intervals[END_INTERVAL] < end &&
//     //             intervals[END_INTERVAL] > start)
//     //         {
//     //             start = intervals[START_INTERVAL];
//     //         }
//     //         //  #2
//     //         else if (intervals[START_INTERVAL] > start && intervals[END_INTERVAL] > end &&
//     //                  intervals[START_INTERVAL] < end)
//     //         {
//     //             end = intervals[END_INTERVAL];
//     //         }
//     //         //  #3
//     //         else if (intervals[START_INTERVAL] > start && intervals[END_INTERVAL] < end)
//     //         {
//     //             continue;
//     //         }
//     //         //  #4
//     //         else if (intervals[START_INTERVAL] < start && intervals[END_INTERVAL] > end)
//     //         {
//     //             end = intervals[END_INTERVAL];
//     //             start = intervals[START_INTERVAL];
//     //         }
//     //         else if (intervals[START_INTERVAL] == start && intervals[END_INTERVAL] == end)
//     //         {
//     //             continue;
//     //         }
//     //         else
//     //         {
//     //             continue;
//     //         }
//     //         // merged_intervals = (int*)realloc(merged_intervals, sizeof(int) * ((j + 1) * 2));
//     //         // merged_intervals[START_INTERVAL] = start;
//     //         // merged_intervals[END_INTERVAL] = end;
//     //         // merged_size++;
//     //     }

//     //     merged_intervals = (int*)realloc(merged_intervals, sizeof(int) * ((i + 1) * 2));
//     //     merged_intervals[i /*START_INTERVAL*/ ] = start;
//     //     merged_intervals[i + 1 /*END_INTERVAL*/ ] = end;
//     //     merged_size++;
//     // }

//     for (int i = 0; i < merged_size * 2; i++)
//     {
//         printf("%d ", merged_intervals[i]);
//     }
//     printf("\n");
        
//     *returnSize = merged_size;
//     return merged_intervals;
// }
