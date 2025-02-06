#include <iostream>
using namespace std;

int main()
{
  int b,d,e;
  cout<<"Введите количество отрезков, для которых хотите найти пересечение: \n";
  cin>>b;

  int** otr = new int* [b]; //создание матрицы координат
  for (int i = 0; i<b; i++)
    otr[i] = new int[4];

  int * a = new int [b];

  for(int i = 0; i<b; i++) //заполнение матрицы координат
  {
    cout<<"Введите координаты для вектора "<<i+1<<": \n";
    cout<<"x1=";
    cin>>otr[i][0];
    cout<<"y1=";
    cin>>otr[i][1];
    cout<<"x2=";
    cin>>otr[i][2];
    cout<<"y1=";
    cin>>otr[i][3];
  }

  for(int i = 0; i<b; i++)
  {
    if(otr[i][0]>otr[i][2])
    {
      e = otr[i][0];
      otr[i][0] = otr[i][2];
      otr[i][2] = e;
      e = otr[i][1];
      otr[i][1] = otr[i][3];
      otr[i][3] = e;
    }
    if(otr[i][1]==otr[i][3])
      a[i]=0;
    else
      a[i]=(otr[i][3]-otr[i][1])/(otr[i][2]-otr[i][0]);
  }

  for(int i = 0; i<b-1; i++)
    for(int j =i+1; j<b;j++)
    {
      if(a[i]==a[j])
        cout<<"Отрезки"<<i<<"и"<<j<<"параллельны \n";
      else
      {
        if((otr[i][0]<=otr[j][2] and otr[j][2]<=otr[i][2])or(otr[i][0]<=otr[j][1] and otr[j][1]<=otr[i][2]))
          cout<<"Отрезки "<<i+1<<" и "<<j+1<<" пересекаются \n";
        else
          cout<<"Отрезки "<<i+1<<" и "<<j+1<<" не пересекаются\n";
      }
    }

  for(int i=0;i<b;i++) //удаление матрицы
    delete [] otr[i];
  delete [] otr;
  delete [] a;
}
