#include <stdio.h>
#include <stdlib.h>
#define k 5

int comp(const int *i, const int *j)
{
  return *i-*j;
}

int main(void)
{
  int m[k]={4,3,7,9,1};
  int i;
  printf("Неотсортированный массив\n");
  for (i=0;i<k;i++)
    printf("%i\n",m[i]);
  qsort(m,k,sizeof(int),(int(*)(const void *,const void *)) comp);
  printf("Отсортированный массив\n");
  for (i=0;i<k;i++)
    printf("%i\n",m[i]);
  // printf("Количество перестановок %i\n",);
  return 0;
}
