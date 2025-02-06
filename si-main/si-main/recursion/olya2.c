#include <stdio.h>
void move (int n, char from, char to, char centre)
{
  if (n>0)
  {
    move (n-1,from,centre,to);
    printf("\t %c->%c\n",from,to);
    move(n-1,centre,to,from);
  }
}
int main()
{
  int n;
  printf("количество:");
  scanf("%d",&n);
  move(n,'a','c','b');
}
