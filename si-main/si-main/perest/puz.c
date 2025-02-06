#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define k 5

void rec(int *p,int sum)
{
  int *per;
  int kol=0;
  for (int i=0;i<4;i++)
  {
    printf("p в цикл= %d\n",*p);
    printf("p+1 в цикл= %d\n",*p+1);
    if(*p>*(p+1))
    {
      *per=*p;
      *p=*p+1;
      *p+1=*per;
      kol++;
    }
    p++;
  }
  sum=sum+kol;
  *p=*(p-2);
  if(kol>0)
  {
    rec(p,sum);
  }
  else
    printf("Количество перестановок %i\n",sum);
}

int main()
{
  int m[k]={4,3,7,9,1};
  int *p;
  int i;
  int sum=0;
  printf("Неотсортированный массив\n");
  for (i=0;i<k;i++)
    printf("m[%i]= %i\n",i,m[i]);
  p=&m[0];
  rec(p,sum);
  printf("Отсортированный массив\n");
  for (i=0;i<k;i++)
  {
    printf("%i\n",*p);
    *p++;
  }
  return 0;
}
