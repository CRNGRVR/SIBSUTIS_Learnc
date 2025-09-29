#!/bin/bash

PROGRAM="./bin/exercise5"

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

echo "Тестирование программы умножения матриц: $PROGRAM"
echo "=================================================="

check_result() {
    local expected="$1"
    local result="$2"
    local test_name="$3"
    
    if [ "$result" = "$expected" ]; then
        echo "✓ PASS: $test_name"
        return 0
    else
        echo "✗ FAIL: $test_name"
        echo "  Ожидалось: $expected"
        echo "  Получено:  $result"
        return 1
    fi
}

echo "Тест 1: Умножение на единичную матрицу"
matrix1=()
for ((i=0; i<10; i++)); do
    for ((j=0; j<3; j++)); do
        matrix1+=($((i*3 + j + 1)))
    done
done

matrix2=()
for ((i=0; i<3; i++)); do
    for ((j=0; j<10; j++)); do
        if [ $i -eq $j ]; then
            matrix2+=(1)
        else
            matrix2+=(0)
        fi
    done
done

expected_start="1.00 2.00 3.00"
result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")

if [[ "$result" == "$expected_start"* ]]; then
    echo "✓ PASS: Умножение на единичную матрицу"
else
    echo "✗ FAIL: Умножение на единичную матрицу"
    echo "  Результат должен начинаться с: $expected_start"
    echo "  Получено: ${result:0:50}..."
fi

echo "Тест 2: Матрицы с одинаковыми элементами"
matrix1=()
for ((i=0; i<30; i++)); do
    matrix1+=(2)
done

matrix2=()
for ((i=0; i<30; i++)); do
    matrix2+=(3)
done

result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")
if echo "$result" | grep -q "18.00" && ! echo "$result" | grep -q -v "18.00"; then
    echo "✓ PASS: Все элементы равны 18.00"
else
    echo "✗ FAIL: Не все элементы равны 18.00"
    echo "  Первые элементы: $(echo "$result" | cut -d' ' -f1-5)"
fi

echo "Тест 3: Нулевые матрицы"
matrix1=()
matrix2=()
for ((i=0; i<30; i++)); do
    matrix1+=(0)
    matrix2+=(0)
done

result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")
if echo "$result" | grep -q "0.00" && ! echo "$result" | grep -q -v "0.00"; then
    echo "✓ PASS: Все элементы равны 0.00"
else
    echo "✗ FAIL: Не все элементы равны 0.00"
    echo "  Первые элементы: $(echo "$result" | cut -d' ' -f1-5)"
fi

echo "Тест 4: Проверка размера результата"
matrix1=()
matrix2=()
for ((i=1; i<=30; i++)); do
    matrix1+=($i)
    matrix2+=($i)
done

result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")
element_count=$(echo "$result" | wc -w)
if [ "$element_count" -eq 100 ]; then
    echo "✓ PASS: Результат содержит 100 элементов"
else
    echo "✗ FAIL: Результат содержит $element_count элементов, ожидалось 100"
fi

echo "Тест 5: Специфический паттерн"
matrix1=()
for ((i=0; i<10; i++)); do
    matrix1+=(1 0 0)
done

matrix2=()
for ((i=0; i<3; i++)); do
    for ((j=0; j<10; j++)); do
        if [ $j -eq 0 ]; then
            matrix2+=(1)
        else
            matrix2+=(0)
        fi
    done
done

result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")
first_element=$(echo "$result" | cut -d' ' -f1)
if [ "$first_element" = "1.00" ]; then
    echo "✓ PASS: Первый элемент равен 1.00"
else
    echo "✗ FAIL: Первый элемент равен $first_element, ожидалось 1.00"
fi

echo "Тест 6: Вещественные числа"
matrix1=()
matrix2=()
for ((i=0; i<30; i++)); do
    matrix1+=(0.5)
    matrix2+=(2.0)
done

result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")
if echo "$result" | grep -q "3.00" && ! echo "$result" | grep -q -v "3.00"; then
    echo "✓ PASS: Все элементы равны 3.00"
else
    echo "✗ FAIL: Не все элементы равны 3.00"
fi

echo "Тест 7: Проверка формата вывода"
matrix1=()
matrix2=()
for ((i=0; i<30; i++)); do
    matrix1+=(1)
    matrix2+=(1)
done

result=$(echo "${matrix1[@]}" "${matrix2[@]}" | "$PROGRAM")
if echo "$result" | grep -q -E '^[0-9.-]+(\.[0-9]+)?( [0-9.-]+(\.[0-9]+)?)*$'; then
    echo "✓ PASS: Корректный формат вывода"
else
    echo "✗ FAIL: Некорректный формат вывода"
    echo "  Вывод: $result"
fi

echo "=================================================="
echo "Тестирование завершено"