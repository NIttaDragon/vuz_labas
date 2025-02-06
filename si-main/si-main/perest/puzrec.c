#include <stdio.h>
#define k 5

int perest(int* p)
{
  int* per;
  int flag=0;
  for (int i=0;i<4;i++)
  {
    if(*p>*(p+1))
    {
      *per=*p;
      *p=*(p+1);
      *(p+1)=*per;
      flag++;
    }
    *p++;
  }
  return(flag);
}
int main()
{
  int m[k]={2,3,7,9,1};
  int *p;
  int i,a;
  int kol=0;
  printf("Неотсортированный массив\n");
  for (i=0;i<k;i++)
    printf("%i\n",m[i]);
  p=&m;
  do{
    a=perest(p);
    kol=kol+a;
  } while (a>0);
  printf("Отсортированный массив\n");
  for (i=0;i<k;i++)
  {
    printf("%i\n",*p);
    *p++;
  }
  printf("Количество перестановок %i\n",kol);
  return 0;
}
