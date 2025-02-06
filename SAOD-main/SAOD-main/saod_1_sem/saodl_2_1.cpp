#include <iostream>
#include "saodl2.1.h"
using namespace std;

MQueue::MQueue(int n) //конструктор
{
  //int *arr = new int [n];
  for (int i=0;i<n;i++)
  {
    arr[i]=0;
  }
}
void show(int n) //вывод очереди на экран
{
  for (int i=0;i<n;i++)
  {
    cout<<arr[i];
  }
}
void zap(int a) //заполнение очереди
{
  for (int i=0;i<n;i++)
  {
    arr[i]=a;
  }
}
void del(int n) //удаление первого элемента очереди
{
  for(int i=0;i<(n-1);i++)
  {
    arr[i]=arr[i+1];
  }
}
int kol(int n) //вычисление размера массива
{
  n=sizeof(arr)/sizeof(arr[0]);
  return(n);
}
// void dob(int a) //добавление в конец очереди
// {
//   n=kol();
//   arr[n]
// }

MQueue::~MQueue() //деструктор
