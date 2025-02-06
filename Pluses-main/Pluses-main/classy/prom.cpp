#include <iostream>
#include "headprom.h"
using namespace std;

int main()
{
  Matrix<int> M(3,3);
  //заполнение значениями
  int i,j,c,k,b,x,y,z;
  for(i=0;i<3;i++)
    for(j=0;j<3;j++)
      M.SetMij(i,j,0);
  cout<<"Начальная матрица"<<endl;
  M.Print("M");
  while (k!=0)
  {
    cout<<endl;
    cout<<"Что хотите сделать с матрицей:"<<endl;
    cout<<"1. Умножить"<<endl;
    cout<<"2. Транспонировать"<<endl;
    cout<<"3. Изменить точечное значение в матрице"<<endl;
    cout<<"4. Скопировать матрицу"<<endl;
    cout<<"5. Вернуть начальную матрицу"<<endl;
    cout<<"6. Ничего, завершить программу"<<endl;
    cout<<"Ваш выбор: ";
    cin>>b;
    switch (b)
    {
      case 1:
      {
        cout<<endl;
        cout<<"Введите число, на которое нужно умножить матрицу: ";
        cin>>c;
        cout<<endl;
        cout<<"Умноженная матрица: "<<endl; //Умножение матрицы
        M.PrintYmn(c,"M");
        break;
      }
      case 2:
      {
        cout<<endl;
        cout<<"Транспонированная матрица: "<<endl; //Транспонирование матрицы
        M.PrintTransp("M");
        break;
      }
      case 3:
      {
        cout<<endl;
        cout<<"Введите номер элемента, который хотите изменить "<<endl;
        cout<<"Номер строки: ";
        cin>>x;
        cout<<"Номер столбца: ";
        cin>>y;
        if ((x>3)||(y>3))
          cout<<"Ошибка номера элемента, выход за границу значений. Попробуйте ввести другие значения."<<endl;
        else
        {
          cout<<"Введите новое значение элемента: ";
          cin>>z;
          M.SetMij(x-1,y-1,z);
          M.Print("M");
        }
        break;
      }
      case 4:
      {
        cout<<endl;
        cout<<"Скопированная матрица"<<endl;
        Matrix<int> M2=M;
        M2.Print("M2");
        break;
      }
      case 5:
      {
        cout<<endl;
        cout<<"Начальная матрица"<<endl;
        for(i=0;i<3;i++)
          for(j=0;j<3;j++)
            M.SetMij(i,j,0);
        M.Print("M");
        break;
      }
      case 6:
      {
        k=0;
        break;
      }
    }
  }
}
