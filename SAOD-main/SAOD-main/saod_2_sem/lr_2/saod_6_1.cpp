#include <iostream>
#include <string>
//#include <algorithm>
using namespace std;

int main()
{
  int b,c,d,e,g; //получение строк
  cout<<"Введите вместимость рюкзака: \n";
  cin>>b;
  cout<<"Введите количество предметов: \n";
  cin>>c;

  int** a ; //создание матрицы предметов
  a = new int* [c];
  for (int i = 0; i<c; i++)
    a[i] = new int[2];

  for(int i = 0; i<c; i++) //заполнение матрицы предметов
  {
    cout<<"Введите стоимость предмета "<<i+1<<": \n";
    cin>>d;
    a[i][0] = d;
    cout<<"Введите вес предмета: \n";
    cin>>e;
    a[i][1] = e;
  }

  for(int i=0;i<c;i++) //сортировка по возрастанию цены и уменьшению веса
    for(int j=0;j<c-1;j++)
    {
      if(a[j][0]<a[j+1][0])
      {
        g=a[j][0];
        a[j][0]=a[j+1][0];
        a[j+1][0]=g;
        g=a[j][1];
        a[j][1]=a[j+1][1];
        a[j+1][1]=g;
      }
      else if((a[j][0]==a[j+1][0])and(a[j][1]>a[j+1][1]))
      {
        g=a[j][1];
        a[j][1]=a[j+1][1];
        a[j+1][1]=g;
      }
    }

  int s=0; int k=0; int f=0; int i=0;

  while(i<c) //заполнение рюкзака
  {
    if(f+a[i][1]<=b)
    {
      f=f+a[i][1];
      k++;
      s=s+a[i][0];
    }
    i++;
  }

  cout<<"Вы положили в рюкзак: "<<k<<" вещей на общую стоимость: "<<s<<" и весом: "<<f<<endl;

  for(int i=0;i<c;i++) //удаление матрицы
    delete [] a[i];
  delete [] a;
}
