# include <iostream>
//#include <queue>
#include "saodl2.1.cpp"
using namespace std;

int main()
{
  MQueue Q;
  MQueue *Q2 = new MQueue;
  int n,c,b;
  cout<<"Введите размер очереди"<<endl;
  cin>>n;
  int *arr = new int [n];
  MQueue Q1(n);
  cout<<"Введите элементы"<<endl;
  for (int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    Q2->zap(a);
  }
  cout<<endl;
  int e=1;
  while (e!=0)
  {
    n=Q.size();
    cout<<endl;
    cout<<"Выберите действие:"<<endl;
    //cout<<"1. Добавить элемент в начало очереди"<<endl;
    cout<<"2. Добавить элемент в очередь"<<endl;
    cout<<"3. Вывести очередь на экран"<<endl;
    cout<<"4. Удалить первый элемент очереди"<<endl;
    cout<<"5. Завершить программу"<<endl;
    cin>>b;
    cout<<endl;
    switch(b)
    {
      /*case 1:
        cout<<"Введите новый элемент"<<endl;
        cin>>c;
        for(int i=0;i<n;i++)
        {
          arr[i]=q.front();
          q.pop();
        }
        q.push(c);
        for(int i=0;i<n;i++)
        {
          c=arr[i];
          q.push(c);
        }
        break;*/
      case 2:
        cout<<"Введите новый элемент"<<endl;
        cin>>c;
        q.push(c);
        break;
      case 3:
        if(n!=0)
        {
          Q2->show(n);
          //cout<<"Очередь не пуста"<<endl;
        }
        else
        {
          cout<<"Очередь пуста"<<endl;
        }
        break;
      case 4:
        Q2->del();
        break;
      case 5:
        e=0;
        break;
    }
  }
  /*queue <int> q;
  int n,c,b;
  cout<<"Введите размер очереди"<<endl;
  cin>>n;
  cout<<"Введите элементы"<<endl;
  for (int i=0;i<n;i++)
  {
    int a;
    cin>>a;
    q.push(a);
  }
  cout<<endl;
  int *arr = new int [n];
  int e=1;
  while (e!=0)
  {
    n=q.size();
    cout<<endl;
    cout<<"Выберите действие:"<<endl;
    cout<<"1. Добавить элемент в начало очереди"<<endl;
    cout<<"2. Добавить элемент в конец очереди"<<endl;
    cout<<"3. Вывести очередь на экран"<<endl;
    cout<<"4. Удалить первый элемент очереди"<<endl;
    cout<<"5. Завершить программу"<<endl;
    cin>>b;
    cout<<endl;
    switch(b)
    {
      case 1:
        cout<<"Введите новый элемент"<<endl;
        cin>>c;
        for(int i=0;i<n;i++)
        {
          arr[i]=q.front();
          q.pop();
        }
        q.push(c);
        for(int i=0;i<n;i++)
        {
          c=arr[i];
          q.push(c);
        }
        break;
      case 2:
        cout<<"Введите новый элемент"<<endl;
        cin>>c;
        q.push(c);
        break;
      case 3:
        if(!q.empty())
        {
          for(int i=0;i<n;i++)
          {
            cout<<q.front()<<endl;
            q.pop();
          }
          //cout<<"Очередь не пуста"<<endl;
        }
        else
        {
          cout<<"Очередь пуста"<<endl;
        }
        break;
      case 4:
        q.pop();
        break;
      case 5:
        e=0;
        break;
    }
  }*/
  return 0;
}
