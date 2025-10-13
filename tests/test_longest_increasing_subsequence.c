#include <stdlib.h>
#include <string.h>
#include "../extra/Unity/unity.h"
#include "../include/advanced_array_function.h"

void setUp(void) {}

void tearDown(void) {}

// Тест 1: Базовый случай из классического примера
void test_lis_basic_case(void) {
    int nums[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 4; // [2, 3, 7, 101] или [2, 5, 7, 101]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 2: Уже отсортированный массив
void test_lis_sorted_array(void) {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 8;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 3: Обратно отсортированный массив
void test_lis_reverse_sorted(void) {
    int nums[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 1; // Любой один элемент
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 4: Все элементы одинаковые
void test_lis_all_equal(void) {
    int nums[] = {5, 5, 5, 5, 5, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 1; // Только один элемент в подпоследовательности
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 5: Один элемент
void test_lis_single_element(void) {
    int nums[] = {42};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 1;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 6: Пустой массив
void test_lis_empty_array(void) {
    int* nums = NULL;
    int numsSize = 0;
    int expected = 0;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 7: Чередующиеся последовательности
void test_lis_alternating_sequence(void) {
    int nums[] = {1, 3, 2, 4, 3, 5, 4, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 5; // Например, [1, 2, 3, 4, 6] или [1, 3, 4, 5, 6]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 8: Отрицательные числа
void test_lis_negative_numbers(void) {
    int nums[] = {-5, -3, -7, -2, -8, -1, -4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 4; // [-7, -2, -1] или [-5, -3, -2, -1]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 9: Смешанные положительные и отрицательные числа
void test_lis_mixed_numbers(void) {
    int nums[] = {-2, 1, -1, 2, 0, 3, -3, 4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 5; // [-2, -1, 0, 3, 4] или [-2, 1, 2, 3, 4]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 10: Большие числа
void test_lis_large_numbers(void) {
    int nums[] = {1000000, 1000001, 999999, 1000002, 1000000};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 3; // [1000000, 1000001, 1000002]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 11: Строго возрастающая с пропусками
void test_lis_strictly_increasing_with_gaps(void) {
    int nums[] = {1, 5, 10, 15, 20, 25};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 6;
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 12: Почти отсортированный массив
void test_lis_almost_sorted(void) {
    int nums[] = {1, 2, 4, 3, 5, 6, 8, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 6; // [1, 2, 3, 5, 6, 8] или [1, 2, 4, 5, 6, 8]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 13: Дубликаты в середине возрастающей последовательности
void test_lis_duplicates_in_middle(void) {
    int nums[] = {1, 2, 2, 3, 3, 3, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 5; // [1, 2, 3, 4, 5] (дубликаты не считаются)
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 14: Длинная последовательность с одним нарушением
void test_lis_long_sequence_one_break(void) {
    int nums[] = {1, 2, 3, 4, 5, 0, 6, 7, 8};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 7; // [1, 2, 3, 4, 5, 6, 7, 8] без 0
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 15: Волнообразная последовательность
void test_lis_wave_sequence(void) {
    int nums[] = {5, 1, 6, 2, 7, 3, 8, 4, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 5; // Например, [1, 2, 3, 4, 9] или [1, 6, 7, 8, 9]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 16: Случай из LeetCode
void test_lis_leetcode_example(void) {
    int nums[] = {0, 1, 0, 3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 4; // [0, 1, 2, 3]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 17: Другой сложный случай
void test_lis_complex_case(void) {
    int nums[] = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 6; // [3, 5, 6, 7, 12] или [2, 4, 5, 6, 7, 12]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 18: Большой массив для проверки производительности
void test_lis_large_array(void) {
    int nums[] = {
        1, 7, 3, 8, 4, 9, 2, 10, 5, 11, 6, 12,
        13, 19, 14, 20, 15, 21, 16, 22, 17, 23, 18, 24
    };
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 13; // Можно получить длинную последовательность
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 19: Все элементы убывают кроме последнего
void test_lis_decreasing_with_last_increase(void) {
    int nums[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 2; // [1, 10] или [9, 10]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

// Тест 20: Пилообразная последовательность
void test_lis_sawtooth_sequence(void) {
    int nums[] = {1, 10, 2, 9, 3, 8, 4, 7, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int expected = 5; // [1, 2, 3, 4, 5] или [1, 2, 3, 4, 6]
    
    int result_default = length_of_lis(nums, numsSize);
    
    TEST_ASSERT_EQUAL_INT(expected, result_default);
}

int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_lis_basic_case);
    RUN_TEST(test_lis_sorted_array);
    RUN_TEST(test_lis_reverse_sorted);
    RUN_TEST(test_lis_all_equal);
    RUN_TEST(test_lis_single_element);
    RUN_TEST(test_lis_empty_array);
    RUN_TEST(test_lis_alternating_sequence);
    RUN_TEST(test_lis_negative_numbers);
    RUN_TEST(test_lis_mixed_numbers);
    RUN_TEST(test_lis_large_numbers);
    RUN_TEST(test_lis_strictly_increasing_with_gaps);
    RUN_TEST(test_lis_almost_sorted);
    RUN_TEST(test_lis_duplicates_in_middle);
    RUN_TEST(test_lis_long_sequence_one_break);
    RUN_TEST(test_lis_wave_sequence);
    RUN_TEST(test_lis_leetcode_example);
    RUN_TEST(test_lis_complex_case);
    RUN_TEST(test_lis_large_array);
    RUN_TEST(test_lis_decreasing_with_last_increase);
    RUN_TEST(test_lis_sawtooth_sequence);
    
    return UNITY_END();
}
