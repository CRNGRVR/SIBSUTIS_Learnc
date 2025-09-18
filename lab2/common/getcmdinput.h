#ifndef _GETCMDINPUT
#define _GETCMDINPUT 1

/*
    getcmdinput - парсер аргументов командной строки на целочисленные значения

    expected  - требуемое количество аргументов
    real      - реально переданное кол-во аргументов. Принимает argc
    cmdInput  - массив строк аргументов. Принимает argv
    erroutput - строка, которая будет отображена в случае несоответствия expected и real

    Возвращает указатель на массив чисел в случае успеха или NULL в случае ошибки.
    
    После завершения работы с числами необходимо высвободить память
    функцией clearcmdinput
*/
int *getcmdinput(int expected, int real, char **cmdInput,
                 const char *erroutput);

/*
    clearcmdinput - высвобождение памяти, используемой функцией getcmdinput

    numbers - указатель на область памяти
*/
void clearcmdinput(int *numbers);

#endif
