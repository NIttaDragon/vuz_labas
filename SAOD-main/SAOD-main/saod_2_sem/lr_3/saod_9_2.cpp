#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int dano, g, pred_i, max_x = 0, x, y, k, kol = 0, l = 1, nov_i, i, j;
  float min_f = 1000, max_r = 0, f, r, fu;

  cout<<"Введите количество точек: \n";
  cin>>dano;

  int** tochki = new int* [dano]; //создание матрицы
  for (int i = 0; i<dano; i++)
    tochki[i] = new int[2];

  int* obolochka = new int [dano];  //точки оболочки

  for(i = 0; i<dano; i++) //заполнение матрицы
  {
    cout<<"Введите координаты для точки "<<i+1<<": \n";
    cout<<"x=";
    cin>>tochki[i][0];
    cout<<"y=";
    cin>>tochki[i][1];
  }

  for(i = 0; i < dano; i++) //сортировка по возрастанию x и y
    for(j = 0; j < dano-1; j++)
    {
      if(tochki[j][0]>tochki[j+1][0])
      {
        g=tochki[j][0];
        tochki[j][0]=tochki[j+1][0];
        tochki[j+1][0]=g;
        g=tochki[j][1];
        tochki[j][1]=tochki[j+1][1];
        tochki[j+1][1]=g;
      }
      else if((tochki[j][0]==tochki[j+1][0])and(tochki[j][1]>tochki[j+1][1]))
      {
        g=tochki[j][1];
        tochki[j][1]=tochki[j+1][1];
        tochki[j+1][1]=g;
      }
    }

  for(i = 0; i < dano; i++) //нахождение начальной точки оболочки
  {
    if(tochki[i][0] > max_x)
    {
      max_x = tochki[i][0];
      pred_i = i;
    }
  }
  cout<<"Нулевая точка ("<<tochki[pred_i][0]<<";"<<tochki[pred_i][1]<<")\n";

  int mau = pred_i;

  for(i = 0; i<dano; i++)
  {
    if(i!=mau)
    {
      x = tochki[i][0] - tochki[pred_i][0];
      y = tochki[i][1] - tochki[pred_i][1];
      if(x == 0)
        if(y > 0)  f = 90;
      else
      {
        f = atan2(y,x)*180/3.14;
        fu = f;
        if (f==0)
          if(x>0) f = 0;
          else if(x<0) f = 360;
        else if(y< 0)  f = f + 360;
      }
      if(f < min_f)
      {
        min_f = f;
        r = sqrt(x*x+y*y);
        nov_i = i;
      }
      else if(f==min_f)
      {
        r = sqrt(x*x+y*y);
        if(r > max_r)
        {
          max_r = r;
          nov_i = i;
        }
      }
    }
    cout<<tochki[i][0]<<" > "<<x<<" "<<tochki[i][1]<<" > "<<y<<" f = "<<f<<" fu = "<<fu<<" r = "<<r<<endl;
    cout<<min_f<<" "<<max_r<<" "<<nov_i<<endl;
    cin>>g;
  }
  obolochka[kol] = nov_i;
  pred_i = nov_i;
  cout<<"Первая точка ("<<tochki[nov_i][0]<<";"<<tochki[nov_i][1]<<")\n";
  kol++;

  while(mau!=pred_i)
  {
    min_f = 1000, max_r = 0;
    for(i = 0; i<dano; i++)
    {
      for(j = 0; j<kol; j++)
      {
        if(i==obolochka[j])  k = obolochka[j];
      }
      if(i!=k)
      {
        x = tochki[i][0] - tochki[pred_i][0];
        y = tochki[i][1] - tochki[pred_i][1];
        if(x == 0)
        {
          if(y > 0)  f = 90;
          else  if(l=1)
                {
                  f = 270;
                  l = 0;
                }
                else
                {
                  f = -90;
                  l = 1;
                }
          fu = f;
        }
        else
        {
          f = atan2(y,x)*180/3.14;
          fu = f;
          if(y < 0)  f = f + 360;
        }
        if(f < min_f)
        {
          min_f = f;
          r = sqrt(x*x+y*y);
          nov_i = i;
          max_r = r;
        }
        else if(f==min_f)
        {
          r = sqrt(x*x+y*y);
          if(r > max_r)
          {
            max_r = r;
            nov_i = i;
          }
        }
        cout<<tochki[i][0]<<" > "<<x<<" "<<tochki[i][1]<<" > "<<y<<" "<<f<<" "<<fu<<" "<<r<<endl;
        cout<<min_f<<" "<<max_r<<" "<<nov_i<<endl;
      }
    cin>>g;
    }
    if(min_f == -90) l = 1;
    else if(min_f == 270) l = 0;
    obolochka[kol] = nov_i;
    pred_i = nov_i;
    kol++;
    cout<<tochki[nov_i][0]<<" "<<tochki[nov_i][1]<<endl;
    cout<<"Оболочка множества состоит из точек:\n";
    for(int i = 0; i<kol; i++)
    {
      cout<<"("<<tochki[obolochka[i]][0]<<";"<<tochki[obolochka[i]][1]<<")\n";
    }
  }

  cout<<"Оболочка множества состоит из точек:\n";
  for(i = 0; i<kol; i++)
  {
    cout<<"("<<tochki[obolochka[i]][0]<<";"<<tochki[obolochka[i]][1]<<")\n";
  }

  for(i = 0; i<dano; i++) //удаление матрицы
    delete [] tochki[i];
  delete [] tochki;
  delete [] obolochka;
}
