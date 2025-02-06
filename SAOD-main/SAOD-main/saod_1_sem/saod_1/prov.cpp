# include <iostream>
using namespace std;

int main()
{
  int a[10]; int b[10];
  int i,j,t,k;
  int l=1; int m=10;
  for (i=0;i<m;i++) //рандомное заполнение массива
    {
      a[i]=rand()%10;
    }
  for(int j=0;j<m;j++)
  {
    cout<<a[j]<<" ";
  }
  cout<<endl;

  while(l!=0) //сортировка пузырьком
  {
    l=0;
    for (i=1;i<m;i++)
    {
      if(a[i-1]>a[i])
      {
        swap(a[i-1], a[i]);
        l++;
      }
    }
  }

  for (i=0;i<m;i++) // сортировка выбором
  {
    int min=m+1;
    for (j=i;j<m;j++)
    {
      if(a[j]<min)
      {
        min=a[j];
        t=j;
      }
    }
    if(a[i]!=min)
    {
      k=a[i];
      a[i]=min;
      a[t]=k;
    }
  }

  for (i=1;i<m;i++) //сортировка вставками
  {
    for (j=0;j<i;j++)
    {
      if(a[i]<a[j])
        swap(a[i], a[j]);
    }
  }

  for(i=0;i<m;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
