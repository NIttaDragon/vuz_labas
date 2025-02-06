#include <iostream>
#include "prem.cpp"
using namespace std;

int main()
{
  Matrix M; //объявление объекта класса
  Matrix *M2=new Matrix;
  int c,k,b,x,y,z;
  int t[4][4];
  cout<<"Начальная матрица"<<endl; //заполнение значениями
  for (int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      t[i][j]=0;
  Matrix M1(t);
  M2->NachMatr();
  M2->show();
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
        cout<<endl; //Умножение матрицы
        cout<<"Введите число, на которое нужно умножить матрицу: ";
        cin>>c;
        cout<<endl;
        cout<<"Умноженная матрица: "<<endl;
        M2->YmnMat(c);
        M2->show();
        break;
      }
      case 2:
      {
        cout<<endl; //Транспонирование матрицы
        cout<<"Транспонированная матрица: "<<endl;
        M2->TraMat();
        M2->show();
        break;
      }
      case 3:
      {
        cout<<endl; //точесное изменение элемента матрицы
        cout<<"Введите номер элемента, который хотите изменить "<<endl;
        cout<<"Номер строки: ";
        cin>>x;
        cout<<"Номер столбца: ";
        cin>>y;
        if ((x>4)||(y>4))
          cout<<"Ошибка номера элемента, выход за границу значений. Попробуйте ввести другие значения."<<endl;
        else
        {
          cout<<"Введите новое значение элемента: ";
          cin>>z;
        }
        M2->IzmTochZn((x-1),(y-1),z);
        M2->show();
        break;
      }
      case 4:
      {
        cout<<endl; // копирование матрицы
        Matrix matr=M;
        break;
      }
      case 5:
      {
        cout<<endl; //вывод начальной матрицы
        cout<<"Начальная матрица"<<endl;
        M2->NachMatr();
        M2->show();
        break;
      }
      case 6:
      {
        k=0;
        break;
      }
    }
  }
  return 0;
}
