#include <iostream>
using namespace std;

int main()
{
  int a[4][4]; int n,i,j;
  for (i=0;i<4;i++)
  {
    for (j=0;j<4;j++)
    {
      cout<<"Элемент a ["<<i+1<<"]["<<j+1<<"]= ";
      cin>>a[i][j];
    }
  }
  cout<<"Начальная матрица: "<<endl;
  for (int i=0;i<4;i++)
  {
    for (int j=0;j<4;j++)
    {
      cout<<a[i][j]<<"   ";
    }
    cout << endl;
  }
  cout<<"Введите число, на которое нужно умножить матрицу: "<<endl;
  cin>>n;
  cout<<"Умноженная матрица: "<<endl;
  for (i=0;i<4;i++)
  {
    for (j=0;j<4;j++)
    {
      cout<<a[i][j]*n<<"    ";
    }
    cout<<endl;
  }
  cout<<"Транспонированная матрица: "<<endl;
  for (int i=0;i<4;i++)
  {
    for (int j=0;j<4;j++)
    {
      cout<<a[j][i]*n<<"   ";
    }
    cout << endl;
  }
  return 0;
}
