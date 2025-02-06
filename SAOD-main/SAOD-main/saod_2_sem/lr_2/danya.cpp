#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string str1,str2,str; //получение строк
  cout<<"Введите первую строку: \n";
  getline(cin, str1);
  int s1 = str1.length()+1;
  cout<<"Введите вторую строку \n";
  getline(cin, str2);
  int s2 = str2.length()+1;

  if (s1<s2)
  {
    int s = s1; s1 = s2; s2 = s;
    str = str1; str1 = str2; str2 = str;
  }

  int** a ; //создание матрицы
  a = new int* [s1];
  for (int i = 0; i<s1; i++)
    a[i] = new int[s2];

  for(int i = 0; i<s1; i++) //заполнение начала матрицы
    a[i][0] = i;
  for(int j = 0; j<s2; j++)
    a[0][j] = j;

  for(int i = 1; i<s1; i++) //заполнение матрицы
    for(int j = 1; j<s2; j++)
    {
      if(str1[i-1]!=str2[j-1])
        a[i][j]=min(min(a[i-1][j]+1,a[i][j-1]+1),a[i-1][j-1]+1);
      else
        a[i][j]=min(min(a[i][j-1]+1,a[i-1][j]+1),a[i-1][j-1]);
    }

  cout<<endl;
  for(int i = 0;i<s1;i++) //вывод матрицы
  {
    for(int j = 0;j<s2;j++)
      cout<<a[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;

  cout<<"Расстояние Левенштейна: "<<a[s1-1][s2-1]<<endl; //решение

  for(int i = 0; i<s1; i++)
    delete [] a[i];
  delete [] a;
}
