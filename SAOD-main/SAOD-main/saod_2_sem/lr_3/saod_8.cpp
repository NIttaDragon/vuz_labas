#include <iostream>
using namespace std;

int main()
{
  int b, maxi, mini, maxx, maxy, minx, miny;
  cout<<"Введите количество точек: \n";
  cin>>b;

  int** toch = new int* [b]; //создание матрицы
  for (int i = 0; i<b; i++)
    toch[i] = new int[2];

  for(int i = 0; i<b; i++) //заполнение матрицы
  {
    cout<<"Введите координаты для точки "<<i+1<<": \n";
    cout<<"x1=";
    cin>>toch[i][0];
    cout<<"y1=";
    cin>>toch[i][1];
  }

  maxx = 0;  minx = 1000;  maxy = 0;  miny = 1000;
  for(int i=0; i<b; i++)
  {
    if(toch[i][0]>=maxx and toch[i][1]>=maxy)
    {
      maxx = toch[i][0];
      maxy = toch[i][1];
      maxi = i;
    }
    if(toch[i][0]<=minx and toch[i][0]<=miny)
    {
      minx = toch[i][0];
      miny = toch[i][1];
      mini = i;
    }
  }

  cout<<"Минимальный элемент множества - ("<<toch[mini][0]<<";"<<toch[mini][1]<<")\n";
  cout<<"Максимальный элемент множества - ("<<toch[maxi][0]<<";"<<toch[maxi][1]<<")\n";

  for(int i=0;i<b;i++) //удаление матрицы
    delete [] toch[i];
  delete [] toch;
}
