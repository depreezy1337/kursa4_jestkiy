#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>
#include "libsorts.h"
int* sortedarr(int size) {
int* sortedarr = (int*)malloc(size * sizeof(int));
if (sortedarr == NULL)
{
printf("Ошибка: не удалось выделить память под массив.\n");
return NULL;
}
for (int i = 0; i < size; i++) {
sortedarr[i] = i + 1;
}
return sortedarr;
}
int* reversedarr(int size) {
int* reversedarr = (int*)malloc(size * sizeof(int));
if (reversedarr == NULL)
{
printf("Ошибка: не удалось выделить память под массив.\n");
return NULL;
}
for (int i = 0; i < size; i++) {
reversedarr[i] = size - i;
}
return reversedarr;
}
int* randomarr(int size) {
int* randomarr = (int*)malloc(size * sizeof(int));
if (randomarr == NULL)
{
printf("Ошибка: не удалось выделить память под массив.\n");
return NULL;
}
srand(time(NULL)); // Инициализация генератора случайных чисел
for (int i = 0; i < size; i++) {
randomarr[i] = rand() % size;
}
return randomarr;
}
int main()
{
setlocale(LC_ALL, "Rus");
int n;
printf("Введите количество элементов в массиве: ");

if (scanf("%d", &n) != 1 || n <= 0)
{
printf("Ошибка: некорректный ввод количества элементов массива.\n");
return 1;
}
int* mass = sortedarr(n);
clock_t start, end;
double cpu_time_used;
start = clock();
shellSort(mass, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Shell sort для упорядоченных по возрастанию данных завершена за %.5f секунд.\n", cpu_time_used);
start = clock();
mergeSort(mass, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Merge sort для упорядоченных по возрастанию данных завершена за %.5f секунд.\n\n", cpu_time_used);
free(mass);
mass = reversedarr(n);
start = clock();
shellSort(mass, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Shell sort для упорядоченных по убыванию данных завершена за %.5f секунд.\n", cpu_time_used);
free(mass);
mass = reversedarr(n);
start = clock();
mergeSort(mass, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Merge sort для упорядоченных по убыванию данных завершена за %.5f секунд.\n\n", cpu_time_used);
free(mass);
mass = randomarr(n);
start = clock();
shellSort(mass, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Shell sort для случайной последовательности данных завершена за %.5f секунд.\n", cpu_time_used);
free(mass);
mass = randomarr(n);
start = clock();
mergeSort(mass, n);
end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("Merge sort для случайной последовательности данных завершена за %.5f секунд.\n", cpu_time_used);
free(mass);
}