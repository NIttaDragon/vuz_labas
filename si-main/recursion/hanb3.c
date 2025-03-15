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
        //printf("\t %c -> %c",a,b);
        printf("\t %c -> %c",b,c);
        move(n-1,a,c,b);
        printf("\t %c->%c\n",a,b);
        printf("\t %c -> %c",c,b);
        printf("\t %c -> %c",b,a);
    }
}
int main()
{
  int n;
  printf("количество:");
  scanf("%d",&n);
  move(n,'a','b','c');
}
