#include <cmath>
using namespace std;

float func4(float x) // y
{
  float zy;
  float s=1.0/3.0;
  zy=pow(sin(x),2)*pow((2+x),s);
  return(zy);
}

void func1() //2.1
{
  float x,y,t;
  cout<<"Введите целое число: ";
  cin>>x;
  y=func4(x);
  if(x<-10)
    y=func4(-10);
  if(x>10)
    y=func4(10);
  cout << setfill('.')<<right<<"y";
  cout<<setw(10)<<y<<endl;
  cout<<left;
}

void func2() //2.2
{
  float x,y1,y2;
  cout<<"Введите целое число x1: ";
  cin>>x;
  y1=func4(x);
  if(x<-10)
    y1=func4(-10);
  if(x>10)
    y1=func4(10);
  cout<<"Введите целое число x2: ";
  cin>>x;
  y2=func4(x);
  if(x<-10)
    y2=func4(-10);
  if(x>10)
    y2=func4(10);
  if (y1!=y2)
        {
          if(y1>y2)
            cout<<"y1>y2"<<endl;
          else
           cout<<"y2>y1"<<endl;
        }
    else
      cout<<"y1=y2"<<endl;
    cout<<" y1= "<<y1;
    cout<<" y2= "<<y2<<endl;
}
void func3() //2.3
{
   float x1,x2,x,l,y,y1,y2;
   cout<<"Введите целое число x1: "; cin>>x1;
   cout<<"Введите целое число x2: "; cin>>x2;
   cout<<"Введите целое число для шага: "; cin>>l;
   if(x1!=x2) //иксы не равны
     {
       if(x1<x2) //х2 больше х1
        {
          if((x2-x1)>l) //возможен шаг
           {
             x=x1;
             while (x<=x2)
             {
               y=func4(x);
               cout<<"x= "<<x;
               cout<<" y= "<<y<<endl;
               x=x+l;
             }
           }
           else//невозможен шаг
           {
             x=x1;
             y1=func4(x);
             x=x2;
             y2=func4(x);
             cout<<"y1= "<<y1<<endl;
             cout<<"y2= "<<y2<<endl;
           }
         }
      else//х1 больше х2
        {
          if((x1-x2)>l)//возможен шаг
          {
            x=x2;
            while (x<=x1)
            {
              y=func4(x);
              cout<<"x= "<<x;
              cout<<" y= "<<y<<endl;
              x=x+l;
             }
          }
          else//шаг невозможен
          {
            x=x1;
            y1=func4(x);
            x=x2;
            y2=func4(x);
            cout<<"y1= "<<y1<<endl;
            cout<<"y2= "<<y2<<endl;
          }
        }
     }
   else
   {
     if(x<-10) y=func4(-10);
     if(x>10) y=func4(10);
     else
      cout<<"Невозможно задать шаг"<<endl;
   }
}
