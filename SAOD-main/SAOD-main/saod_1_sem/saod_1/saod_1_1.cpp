#include <iostream>
using namespace std;

// быстра сортировка

void qsortRecursive(int *a, int m)
{
  int i = 0;
  int j = m - 1;
  int mid = a[m / 2];
  do {
    while(a[i]<mid)
    {
      i++;
    }
    while(a[j]>mid)
    {
      j--;
    }
    if (i <= j)
    {
      swap(a[i],a[j]);
      i++;
      j--;
    }
  } while(i <= j);
  if(j>0)
    qsortRecursive(a,j+1);
  if (i<m)
    qsortRecursive(&a[i],m-i);
}

int main()
{
  int a[10];
  int i;
  int m=10;
  for (i=0;i<m;i++) //рандомное заполнение массива
    {
      a[i]=rand()%10;
    }
  for(i=0;i<m;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  qsortRecursive(a,m);
  for(i=0;i<m;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
