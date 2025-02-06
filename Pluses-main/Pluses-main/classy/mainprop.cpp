#include <iostream>
#include "headprom.h"
using namespace std;

int main()
{
  Matrix<int> M(3,3);
  //заполнение значениями
  int i,j,c;
  for(i=0;i<2;i++)
    for(j=0;j<3;j++)
      M.SetMij(i,j,i+j);
  M.Print("M");
  //вызов конструктора копирования
  Matrix<int> M2=M;
  M2.Print("M2");
  //Транспонирование
  M.PrintTransp("M");
  //Умножение
  cin>>c;
  cout<<endl;
  M.PrintYmn(c,"M");
}
