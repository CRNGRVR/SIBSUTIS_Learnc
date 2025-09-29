#!/bin/bash

# Скрипт для тестирования программы вставки элемента в массив со сдвигом
# Использование: ./test_script.sh <путь_к_программе>

PROGRAM="./bin/exercise4"

if [ -z "$PROGRAM" ]; then
    echo "Ошибка: Укажите путь к программе"
    echo "Использование: $0 <путь_к_программе>"
    exit 1
fi

if [ ! -f "$PROGRAM" ]; then
    echo "Ошибка: Программа '$PROGRAM' не найдена"
    exit 1
fi

if [ ! -x "$PROGRAM" ]; then
    echo "Ошибка: Программа '$PROGRAM' не исполняемая"
    exit 1
fi

echo "Тестирование программы: $PROGRAM"
echo "=========================================="

# Функция для сравнения массивов
compare_arrays() {
    local expected=("$@")
    local actual=("${expected[@]:0:10}")
    expected=("${expected[@]:10}")
    
    for ((i=0; i<10; i++));
    do
        ERROR=$(echo "${expected["$i"]}"'-'"(${actual["$i"]})" | bc -l)
        if [ "$(echo "${ERROR#-}"'>'0.01 | bc -l)" -ne 0 ]; then
            return 1
        fi
    done

    return 0
}

# Тест 1: Вставка в начало
echo "Тест 1: Массив: \"1 2 3 4 5 6 7 8 9 10\". Вставка в начало (K=0, X=99)"
result=$(echo "1 2 3 4 6 6 7 8 9 10" | "$PROGRAM" 99 0)
expected=("99" "1" "2" "3" "4" "5" "6" "7" "8" "9")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 2: Вставка в середину
echo "Тест 2: Массив: \"1 2 3 4 5 6 7 8 9 10\". Вставка в середину (K=5, X=1)"
result=$(echo "1 2 3 4 5 6 7 8 9 10" | "$PROGRAM" 1 5)
expected=("1" "2" "3" "4" "5" "1" "6" "7" "8" "9")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 3: Вставка в конец
echo "Тест 3: Массив: \"1 2 3 4 5 6 7 8 9 10\". Вставка в конец (K=9, X=100)"
result=$(echo "1 2 3 4 5 6 7 8 9 10" | "$PROGRAM" 100 9)
expected=("1" "2" "3" "4" "5" "6" "7" "8" "9" "100")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 4: Вставка отрицательного числа
echo "Тест 4: Массив: \"1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.0\". Вставка отрицательного числа (K=3, X=-5.5)"
result=$(echo "1.1 2.2 3.3 4.4 5.5 6.6 7.7 8.8 9.9 10.0" | "$PROGRAM" -5.5 3)
expected=("1.1" "2.2" "3.3" "-5.5" "4.4" "5.5" "6.6" "7.7" "8.8" "9.9")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 5: Вставка вещественного числа
echo "Тест 5: Массив: \"0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0\". Вставка вещественного числа (K=2, X=3.14)"
result=$(echo "0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1.0" | "$PROGRAM" 3.14 2)
expected=("0.1" "0.2" "3.14" "0.3" "0.4" "0.5" "0.6" "0.7" "0.8" "0.9")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 6: Вставка в предпоследнюю позицию
echo "Тест 6: Массив: \"10 20 30 40 50 60 70 80 90 100\". Вставка в предпоследнюю позицию (K=8, X=999)"
result=$(echo "10 20 30 40 50 60 70 80 90 100" | "$PROGRAM" 999 8)
expected=("10" "20" "30" "40" "50" "60" "70" "80" "999" "90")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 7: Вставка нуля
echo "Тест 7: Массив: \"5 5 5 5 5 5 5 5 5 5\". Вставка нуля (K=1, X=0)"
result=$(echo "5 5 5 5 5 5 5 5 5 5" | "$PROGRAM" 0 1)
expected=("5" "0" "5" "5" "5" "5" "5" "5" "5" "5")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 8: Вставка большого числа
echo "Тест 8: Массив: \"1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5\". Вставка большого числа (K=7, X=9999.99)"
result=$(echo "1.5 2.5 3.5 4.5 5.5 6.5 7.5 8.5 9.5 10.5" | "$PROGRAM" 9999.99 7)
expected=("1.5" "2.5" "3.5" "4.5" "5.5" "6.5" "7.5" "9999.99" "8.5" "9.5")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 9: Вставка с одинаковыми числами
echo "Тест 9: Массив: \"0 0 0 0 0 0 0 0 0 0\". Вставка в массив одинаковых чисел (K=4, X=42)"
result=$(echo "0 0 0 0 0 0 0 0 0 0" | "$PROGRAM" 42 4)
expected=("0" "0" "0" "0" "42" "0" "0" "0" "0" "0")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

# Тест 10: Вставка в позицию 1 (из примера)
echo "Тест 10: Массив: \"1 2 3 4 5 6 7 8 9 10\". Вставка в позицию 1 (K=1, X=5)"
result=$(echo "1 2 3 4 5 6 7 8 9 10" | "$PROGRAM" 5 1)
expected=("1" "5" "2" "3" "4" "5" "6" "7" "8" "9")
if compare_arrays $result "${expected[@]}"; then
    echo "✓ PASS: Ожидалось [${expected[@]}], Получено [$result]"
else
    echo "✗ FAIL: Ожидалось [${expected[@]}], Получено [$result]"
fi

echo "=========================================="
echo "Тестирование завершено"