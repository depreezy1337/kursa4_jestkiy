#include <stdlib.h>
#include <stdio.h>
#include "libsorts.h"
void shellSort(int arr[], int n)
{
int i, j, step;
int data;
for (step = n / 2; step > 0; step /= 2)
for (i = step; i < n; i++)
{
data = arr[i];
for (j = i; j >= step; j -= step)
{
if (data < arr[j - step])
arr[j] = arr[j - step];
else
break;
}
arr[j] = data;
}
}
void Merge(int arr[], int left[], int leftsize, int right[], int rightsize) {
int i = 0, j = 0, k = 0;
while (i < leftsize && j < rightsize) {
if (left[i] <= right[j]) {
arr[k] = left[i];
i++;
}
else {
arr[k] = right[j];
j++;
}
k++;
}
while (i < leftsize) {
arr[k] = left[i];
i++;
k++;
}
while (j < rightsize) {
arr[k] = right[j];
j++;
k++;
}
}
void mergeSort(int arr[], int size) {
if (size < 2) {
return;
}
int mid = size / 2;
int* left = (int*)malloc(mid * sizeof(int));
int* right = (int*)malloc((size - mid) * sizeof(int));
if (left == NULL || right == NULL) {
printf("Ошибка выделения памяти.\n");
exit(1);
}
for (int i = 0; i < mid; i++) {
left[i] = arr[i];
}
for (int i = mid; i < size; i++) {
right[i - mid] = arr[i];
}
mergeSort(left, mid);
mergeSort(right, size - mid);
Merge(arr, left, mid, right, size - mid);
free(left);
free(right);
}
void printarr(int arr[], int size) {
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}