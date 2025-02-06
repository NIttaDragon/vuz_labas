#include <iostream>
#include "prem.h"
using namespace std;
int i,j;
  Matrix::Matrix() //конструктор
  {
    for(i=0;i<m_m;i++)
      for(j=0;j<m_m;j++)
        m_M[i][j]=0;
  }
  Matrix::Matrix(int t[4][4]) //конструктор с параметром
  {
    for (i=0;i<m_m;i++)
      for (j=0;j<m_m;j++)
        m_M[i][j]=t[i][j];
  }
  void Matrix::show() //вывод на экран матрицы
  {
    for (i=0;i<m_m;i++)
    {
      for (j=0;j<m_m;j++)
        cout<<m_M[i][j]<<" ";
      cout<<endl;
    }
  };
  void Matrix::NachMatr() //начальная матрица
  {
    for (i=0;i<m_m;i++)
      for (j=0;j<m_m;j++)
        m_M[i][j]=0;
  };
  void Matrix::TraMat() //транспонирование матрицы
  {
    int a=0;
    for(i=0;i<m_m;i++)
      for(j=i;j<m_m;j++)
      {
        a=m_M[i][j];
        m_M[i][j]=m_M[j][i];
        m_M[j][i]=a;
      }
  };
  void Matrix::YmnMat(int c) //умножение матрицы
  {
    for(i=0;i<m_m;i++)
      for(j=0;j<m_m;j++)
        m_M[i][j]=m_M[i][j]*c;
  };
  void Matrix::IzmTochZn(int x,int y,int z) //изменение точечного значения
  {
    for(i=0;i<m_m;i++)
      for(j=0;j<m_m;j++)
        if((i==x)&&(j==y))
          m_M[i][j]=z;
  };
  Matrix::Matrix(const Matrix &obj) //копирование матрицы
  {
    for(i=0;i<m_m;i++)
      for(j=0;j<m_m;j++)
          m_M[i][j]= obj.m_M[i][j];
    cout<<"Матрица скопирована"<<endl;
  }
  Matrix::~Matrix() //деструктор
  {
    cout<<"Матрица удалена"<<endl;
  }
  ostream& operator<<(ostream &stream, Matrix obj) //перегрузка ввода
  {
    for(i=0;i<obj.m_m;i++)
    {
      for(j=0;j<obj.m_m;j++)
        stream<<obj.m_M[i][j]<<"  " ;
      stream<<endl;
    }
    return stream;
  }
