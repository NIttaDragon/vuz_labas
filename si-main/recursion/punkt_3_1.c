#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
  int x=-100;
  int l=1;
  while(x!=pow(x,2)/pow(x,3))
  {
    //printf("%i\n",x);
    x=x+l;
  }
  printf("найденное число: \n");
  printf("\t %i\n",x);
  return 0;
}
