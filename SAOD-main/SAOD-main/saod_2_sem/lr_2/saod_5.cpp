#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string str1,str2; //получение строк
  cout<<"Введите первую строку: \n";
  getline(cin, str1);
  int s1 = str1.length()+1;
  cout<<"Введите вторую строку \n";
  getline(cin, str2);
  int s2 = str2.length()+1;

  int** a ; //создание матрицы
  a = new int* [s1];
  for (int i = 0; i<s1; i++)
  {
    a[i] = new int[s2];
  }

  for(int i = 1; i<s1; i++) //заполнение начала матрицы
  {
    a[0][i] = i;
    cout<<a[0][i]<<endl;
  }
  for(int j = 1; j<s2; j++)
  {
    a[j][0] = j;
    cout<<a[j][0]<<endl;
  }

  for(int i = 1; i<s1; i++) //заполнение матрицы
  {
    for(int j = 1; j<s2; j++)
    {
      if(str1[i-1]!=str2[j-1])
        a[i][j]=min(min(a[i-1][j]+1,a[i][j-1]+1),a[i-1][j-1]+1);
      else
        a[i][j]=min(min(a[i][j-1]+1,a[i-1][j]+1),a[i-1][j-1]);
    }
  }

  for(int i = 0;i<s1;i++) //вывод матрицы
  {
    for(int j = 0;j<s2;j++)
    {
      cout<<a[i][j]<<" ";
    }
    cout<<endl;
  }

  cout<<endl;
  cout<<a[s1-1][s2-1]<<endl; //решение

  for(int i = 0; i<s1; i++)
  {
    delete [] a[i];
  }
  delete [] a;
}
