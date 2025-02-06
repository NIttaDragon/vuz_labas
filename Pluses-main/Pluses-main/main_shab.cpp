#include <iostream>
#include <string>
#include "specshab.h"
using namespace std;

int main()
{
    int b,c,j,x;
    CArray <char,5> C;
    CArray <float,5> F;
    CArray <int,5> I;
    cout<<"Размер очереди 5"<<endl;
    int k=1;
    while (k!=0)
    {
      cout<<endl;
      cout<<"Что хотите сделать с очередью:"<<endl;
      cout<<"1. Добавить значение в очередь"<<endl;
      cout<<"2. Вывести на экран"<<endl;
      cout<<"3. Удалить значение из очереди"<<endl;
      cout<<"4. Ничего, завершить программу"<<endl;
      cout<<"Ваш выбор: ";
      cin>>b; cout<<endl;
      switch (b)
      {
        case 1:
        {
          cout<<"Какой тип переменных вы хотите ввести:"<<endl;
          cout<<"1. Char"<<endl;
          cout<<"2. Float"<<endl;
          cout<<"3. Integer"<<endl;
          cout<<"Ваш выбор: ";
          cin>>c; cout<<endl;
          switch (c)
          {
            case 1:
            {
              cout<<"Введите переменные"<<endl;
              C.Get();
              j=1;
              break;
            }
            case 2:
            {
              cout<<"Введите переменные"<<endl;
              F.Get();
              j=2;
              break;
            }
            case 3:
            {
              cout<<"Введите переменные"<<endl;
              I.Get();
              j=3;
              break;
            }
          }
        break;
        }
        case 2:
        {
          if(j==1)
            C.Show();
          if(j==2)
            F.Show();
          if(j==3)
            I.Show();
          break;
        }
        case 3:
        {
          cout<<"Введите индекс элемента, который хотите удалить"<<endl;
          cin>>x;
          if(j==1)
            C.del(x);
          if(j==2)
            F.del(x);
          if(j==3)
            I.del(x);
          break;
        }
        case 4:
        {
          k=0;
          break;
        }
      }
    }
    return 0;
}
