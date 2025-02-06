#include <iostream>
#include <string>
using namespace std;

template <typename T,int x> class CArray
{
public:
  T a[x];
  T l;
    CArray() {}; // конструктор
    ~CArray(){}; //деструктор
    T operator [] (int i)  //перегрузка оператора индексации
    {
      if(i<0||i>x-1)
        exit(1);
      return a[i];
    }
    friend ostream& operator<<(ostream& stream, CArray <T,x>& arr)// перегрузка вывода
    {
      for(int i=0;i<x;i++)
        cout<<arr.a[i]<<endl;
    }
    void Get()
    {
      for(int i=0;i<x;i++)
      {
        cin>>l;
        a[i]=l;
      }
    };
    void Show()
    {
      for(int i=0;i<x;i++)
        cout<<a[i]<<endl;
    };
};
