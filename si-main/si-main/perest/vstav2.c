#include <stdio.h>

void insertionSortRecursive(int a[], int n)
{
  if (n <= 1)
    return;
  insertionSortRecursive(a, n - 1);
  int last = a[n - 1];
  int j = n - 2;
  while (j >= 0 && a[j] > last)
  {
    a[j + 1] = a[j];
    j--;
  }
  a[j + 1] = last;
}

void printArray(int a[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", a[i]);
  printf("\n");
}

int main()
{
  int i;
  int a[] = { 12, 11, 13, 5, 6 };
  int n = sizeof(a) / sizeof(a[0]);
  printf("Начальный массив\n");
  for(i=0;i<5;i++)
    printf("%d ",a[i]);
  printf("\n");
  printf("Отсортированный массив\n");
  insertionSortRecursive(a,n);
  printArray(a,n);
  return 0;
}
