#include <iostream>
#include <math.h>
using namespace std;
class CPolygon //объявление класса
{
public:
  int v[4][2];
  float d[4];
  float per=0;
  CPolygon() {}//конструктор класса
  virtual void Zap()
  {
    v[0][0]=0; v[0][1]=0;
    v[1][0]=7; v[1][1]=0;
    v[2][0]=0; v[2][1]=3;
    v[3][0]=5; v[3][1]=6;
  }
  virtual void Perimetr()=0; //вычисление периметра
  virtual void show()=0; //вывод основных характеристик
  ~CPolygon() {}//деструктор
};

class CTriangle:public CPolygon //объявление класса
{
public:
  CTriangle():CPolygon(){}; //конструктор класса
  ~CTriangle() {};//деструктор
  void Perimetr () override
  {
    d[0]=sqrt(pow((v[1][0]-v[0][0]),2)+pow((v[1][1]-v[0][1]),2));
    d[1]=sqrt(pow((v[2][0]-v[1][0]),2)+pow((v[2][1]-v[1][1]),2));
    d[2]=sqrt(pow((v[0][0]-v[2][0]),2)+pow((v[0][1]-v[2][1]),2));
    per=d[0]+d[1]+d[2];
    cout<<"Периметр = "<<per<<endl;
  };
  void show() override
  {
    cout<<"Параметры Треугольника: ";
    cout<<endl<<"Вершины: "<<endl;
    for(int i=0;i<3;i++)
          cout<<"x= "<<v[i][0]<<"   "<<"y= "<<v[i][1]<<endl;
  };
};

class CQuad:public CPolygon //объявление класса
{
public:
  CQuad():CPolygon(){}; //конструктор класса
  ~CQuad() {};//деструктор
  void Perimetr () override
  {
    d[0]=sqrt(pow((v[1][0]-v[0][0]),2)+pow((v[1][1]-v[0][1]),2));
    d[1]=sqrt(pow((v[2][0]-v[1][0]),2)+pow((v[2][1]-v[1][1]),2));
    d[2]=sqrt(pow((v[3][0]-v[2][0]),2)+pow((v[3][1]-v[2][1]),2));
    d[3]=sqrt(pow((v[0][0]-v[3][0]),2)+pow((v[0][1]-v[0][1]),2));
    per=d[0]+d[1]+d[2]+d[3];
    cout<<"Периметр = "<<per<<endl;
  };
  void show() override
  {
    cout<<"Параметры Четырехугольника: ";
    cout<<endl<<"Вершины: "<<endl;
    for(int i=0;i<4;i++)
          cout<<"x= "<<v[i][0]<<"   "<<"y= "<<v[i][1]<<endl;
  };
};
