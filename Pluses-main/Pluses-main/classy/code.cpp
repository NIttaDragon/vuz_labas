#include <iostream>
#include "code.h"
using namespace std;

int main()
{
    Matrica matrix; // Создание объекта класса

    int a[4][4]; // Матрица
    int n,i,j,b;

    cout<<"Начальная матрица: "<<endl; //Вывод начальной матрицы
    for (i=0;i<4;i++)
    {
      for (j=0;j<4;j++)
      {
        a[i][j]=i+j*2;
        cout<<a[i][j]<<"   ";
      }
      cout << endl;
    }
    a=1;
    while (a!=0)
    {
      cout<<"Что хотите сделать с матрицей:"<<endl;
      cout<<"1. Умножить"<<endl;
      cout<<"2.Транспонировать"<<endl;
      cout<<"3. Ничего, завершить программу"<<endl;
      cin>>b;
      switch (b)
      {
        case 1:
        {
          cout<<"Введите число, на которое нужно умножить матрицу: "<<endl;
          cin>>n;
          cout<<"Умноженная матрица: "<<endl; //Умножение матрицы
          for (i=0;i<4;i++)
          {
            for (j=0;j<4;j++)
            {
              cout<<a[i][j]*n<<"    ";
            }
            cout<<endl;
          }
          break;
        }
        case 2:
        {
          cout<<"Транспонированная матрица: "<<endl; //Транспонирование матрицы
          for (int i=0;i<4;i++)
          {
            for (int j=0;j<4;j++)
            {
              cout<<a[j][i]*n<<"   ";
            }
            cout << endl;
          }
          break;
        }
        case 3:
        {
          a=0;
          break;
        }
      }
    }
    return 0;
}
