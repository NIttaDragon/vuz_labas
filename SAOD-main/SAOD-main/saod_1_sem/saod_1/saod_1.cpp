# include <iostream>
#include <cmath>
using namespace std;

int main()
{
  float a[100];
  int i;
  int k;
  int l=1;
  for (i=0;i<100;i++) //рандомное заполнение массива
    {
      a[i]=rand()%100;
    }
  while(l!=0) //сортировка массива
  {
    l=0;
    for (i=1;i<100;i++)
    {
      if(a[i-1]>a[i])
      {
        k=a[i-1];
        a[i-1]=a[i];
        a[i]=k;
        l++;
      }
    }
  }
  /*for(i=1;i<100;i++)
    cout<<a[i]<<endl;
  int mid=100/2; //бинарный поиск
  int key;
  cout<<"Введите ключ"<<endl;
  cin>>key;
  for(i=0;i<7;i++)
  {
    if(key==a[mid])
    {
      cout<<a[mid]<<"  "<<mid<<endl;
      break;
    }
    else
    {
      if((i==6)and(key!=a[mid]))
      {
        cout<<key<<" нет такого элемента"<<endl;
        break;
      }
      else
      {
        if(key>a[mid])
          mid=(mid/2);
        else
          mid=mid-(mid/2);
      }
    }
  }*/
}
