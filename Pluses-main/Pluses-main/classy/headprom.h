#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
private:
  int m; //количество строк
  int n; //количество столбцов
  T** M; //матрица
public:
  //конструкторы
  Matrix()
  {
    n=m=0;
    M=nullptr;
  }
  //конструктор с двумя параметрами
  Matrix(int _m,int _n)
  {
    m=_m;
    n=_n;
    M=(T**) new T*[m];
    for (int i=0;i<m;i++)
      M[i]=(T*) new T[n];
    for (int i=0; i<m;i++)
      for (int j=0;j<n;j++)
        M[i][j]=0;
  }
  //конструктор копирования
  Matrix (const Matrix& _M)
  {
    m= _M.m;
    n= _M.n;
    M=(T**) new T*[m];
    for (int i=0;i<m;i++)
      M[i]=(T*) new T[n];
    for (int i=0; i<m;i++)
      for (int j=0;j<n;j++)
        M[i][j]= _M.M[i][j];
  }
  //методы доступа
  T GerMij(int i,int j)
  {
    if ((m>0)&&(n>0))
      return M[i][j];
    else
      return 0;
  }
  void SetMij (int i, int j, T value)
  {
    if ((i<0)||(i>=m))
      return;
    if ((j<0)||(j>=n))
      return;
    M[i][j]= value;
  }
  //метод вывода матрицы
  void Print(const char* ObjName)
  {
    cout<<"Object: "<<ObjName<<endl;
    for (int i=0;i<m;i++)
    {
      for (int j=0;j<n;j++)
        cout<<M[i][j]<<"\t";
      cout<<endl;
    }
    cout<<"--------------------------------"<<endl<<endl;
  }
  void PrintTransp(const char* ObjName)
  {
    cout<<"Object: "<<ObjName<<endl;
    for (int i=0;i<m;i++)
    {
      for (int j=0;j<n;j++)
        cout<<M[j][i]<<"\t";
      cout<<endl;
    }
    cout<<"--------------------------------"<<endl<<endl;
  }
  void PrintYmn(int c,const char* ObjName)
  {
    cout<<"Object: "<<ObjName<<endl;
    for (int i=0;i<m;i++)
    {
      for (int j=0;j<n;j++)
        cout<<M[j][i]*c<<"\t";
      cout<<endl;
    }
    cout<<"--------------------------------"<<endl<<endl;
  }
  //оператор копирования
  Matrix operator=(const Matrix& _M)
  {
    if(n>0)
    {
      for (int i=0; i<m; i++)
        delete[] M[i];
    }
    if (m>0)
    {
      delete[] M;
    }
    m= _M.m;
    n= _M.n;
    M=(T**) new T*[m];
    for(int i=0;i<m;i++)
      for (int j=0;j<n;j++)
        M[i][j]= _M.M[i][j];
    return *this;
  }
  //деструктор
  ~Matrix()
  {
    if (n>0)
    {
      for (int i=0;i<m;i++)
        delete[] M[i];
    }
    if (m>0)
      delete[] M;
    cout<<"Матрица удалена"<<endl;
  }
  };
