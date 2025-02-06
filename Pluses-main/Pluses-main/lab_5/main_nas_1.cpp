#include <iostream>
#include "specnasnew1.h"
using namespace std;

int main()
{
  CTriangle T; //объект класса
  CQuad Q; //объект класса
  CPolygon *P; //массив указателей
  int k,l,b,n;
  k=1;
  while (k!=0)
  {
    cout<<endl;
    cout<<"Что хотите сделать с объектами:"<<endl;
    cout<<"1. Вывести состояние Четырехугольника"<<endl;
    cout<<"2. Вывести состояние Треугольника"<<endl;
    cout<<"3. Ничего, завершить программу"<<endl;
    cout<<"Ваш выбор: ";
    cin>>b;
    switch (b)
    {
      case 1:
      {
        P=&Q;
        P->Zap();
        P->show();
        P->Perimetr();
        break;
      }
      case 2:
      {
        P=&T;
        P->Zap();
        P->show();
        P->Perimetr();
        break;
      }
      case 3:
      {
        k=0;
        break;
      }
    }
  }
  return 0;
}
