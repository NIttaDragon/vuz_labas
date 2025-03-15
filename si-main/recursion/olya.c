#include <stdio.h>
void move (int n, char a, char b, char c)
{
  if (n==1)
  {
    printf("\t %c -> %c \n",a,b);
    printf("\t %c -> %c \n",b,c);
  }
  else
    {
      move(n-1,a,b,c);
      printf("\t %c -> %c \n",a,b);
      move(n-1,b,c,a);
    }
}
int main()
{
  int n;
  printf("количество:");
  scanf("%d",&n);
  move(n,'a','b','c');
}
