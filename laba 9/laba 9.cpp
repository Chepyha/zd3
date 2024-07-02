#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

long long int merge(int* a, int n)
{
    long long int count=0;
    int mid = n / 2; // находим середину сортируемой последовательности
    if (n % 2 == 1)
        mid++;
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int* c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i = 0;   // индекс первого пути
        int j = mid; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {
            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
                if (a[i] < a[j])
                {
                    count++;
                    c[k] = a[i];
                    count++;
                    i++; k++;
                }
                else {
                    c[k] = a[j];
                    count++;
                    j++; k++;
                }
            }
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = a[i];
                count++;
                i++; k++;
            }
            while ((j < (mid + step)) && (j < n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = a[j];
                count++;
                j++; k++;
            }
            step = step + h; // переходим к следующему 
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        for (i = 0; i < n; i++) {
            a[i] = c[i];
            count++;
        }
    }
    return count;
}

long long int inclusionSort(int* num, int size)
{
    long long int c=0;
    // Для всех элементов кроме начального
    for (int i = 1; i < size; i++)
    {
        int value = num[i]; // запоминаем значение элемента
        c++;
        int index = i; // и его индекс
        c++;
        while ((index > 0) && (num[index - 1] > value))
        {   // смещаем другие элементы к концу массива пока они меньше index
            num[index] = num[index - 1];
            c++;
            index--;    // смещаем просмотр к началу массива
            c++;
        }
        num[index] = value; // рассматриваемый элемент помещаем на освободившееся место
        c++;
    }
    return c;
}

void good(int *a, int c)
{
    for (int i = 0; i < c; i++) a[i] = i;
}

void bad(int *a,int c)
{
    for (int i = 0; i < c; i++) a[i] = c - i;
}

void stand(int *a, int c)
{
    for (int i = 0; i < c; i++) a[i] = rand() % 20 - 10;
}

int main(void)
{
    FILE* f1,*f2,*f3,*f4,*f5,*f6;
    long long int n, c, k;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int *mass;

    f1 = fopen("f1.txt", "w");
    if (f1 == NULL) {
        printf("файл 1 не найден");
        system("pause");
        exit;
    }

    f2 = fopen("f2.txt", "w");
    if (f2 == NULL) {
        printf("файл 1 не найден");
        system("pause");
        exit;
    }

    f3 = fopen("f3.txt", "w");
    if (f3 == NULL) {
        printf("файл 1 не найден");
        system("pause");
        exit;
    }

    f4 = fopen("f4.txt", "w");
    if (f4 == NULL) {
        printf("файл 1 не найден");
        system("pause");
        exit;
    }

    f5 = fopen("f5.txt", "w");
    if (f5 == NULL) {
        printf("файл 1 не найден");
        system("pause");
        exit;
    }

    f6 = fopen("f6.txt", "w");
    if (f6 == NULL) {
        printf("файл 1 не найден");
        system("pause");
        exit;
    }

    c = 1;
    mass = (int*)malloc(sizeof(int) * (c));
    for (c = 500; c <= 50000; c+=500) {
 
        mass= (int*)realloc((void*)mass, sizeof(int) * c);

        good(mass, c);
        k = merge(mass, c);
        printf("%lld    ", k);
        fprintf(f1,"%lld\n",k);
        good(mass,c);
        k = inclusionSort(mass, c);
        printf("%ld               ", k);
        fprintf(f4, "%lld\n", k);

        stand(mass,c);
        k=merge(mass, c);
        printf("%lld    ",k);
        fprintf(f2, "%lld\n", k);
        stand(mass, c);
        k=inclusionSort(mass, c);
        printf("%lld               ",k);
        fprintf(f5, "%lld\n", k);

        bad(mass,c);
        k = merge(mass, c);
        printf("%lld    ", k);
        fprintf(f3, "%lld \n", k);
        bad(mass, c);
        k = inclusionSort(mass, c);
        printf("%lld \n", k);
        fprintf(f6, "%lld \n", k);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    fclose(f6);
    system("pause");
    exit;
}


