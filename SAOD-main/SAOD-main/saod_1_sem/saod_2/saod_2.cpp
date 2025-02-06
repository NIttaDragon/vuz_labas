#include <iostream>
using namespace std;

int main()
{
  int num,a,b;
  cout<<"Введите размер очереди"<<endl;
  cin>>num;
  int *q = new int[num];
  cout<<"Введите очередь"<<endl;
  for (int i=0;i<num;i++)
  {
    int a;
    cin>>a;
    q[i] = a;
  }
  int k=1;
  cout<<"Что хотите сделать с очередью"<<endl;
  while(k!=0)
  {
    cout<<"1. Добавить элемент в конец очереди"<<endl;
    cout<<"2. Вывести очередь на экран"<<endl;
    cout<<"3. Удалить первый элемент очереди"<<endl;
    cout<<"4. Выйти из программы"<<endl;
    cin>>a;
    switch(a)
    {
      case 1:
      {
        num++;
        int *q1 = new int[num];
        for(int i = 0;i<num-1;i++)
          q1[i]=q[i];
        cout<<"Введите значение"<<endl;
        cin>>a;
        q1[num-1]=a;
        delete [] q;
        int *q = new int[num];
        for(int i =0;i<num;i++)
          q[i]=q1[i];
        delete [] q1;
        break;
      }
      case 2:
      {
        if(num!=0)
        {
          for(int i=0;i<num;i++)
            cout<<q[i]<<", ";
          cout<<endl;
        }
        else
          cout<<"Очередь пуста"<<endl;
        break;
      }
      case 3:
      {
        num--;
        int *q1 = new int[num];
        for(int i =1;i<num+1;i++)
          q1[i-1]=q[i];
        cout<<endl;
        delete [] q;
        int *q = new int[num];
        for(int i =0;i<num;i++)
          q[i]=q1[i];
        delete [] q1;
        break;
      }
      case 4:
      {
        k=0;
        break;
      }
    }
  }
  return 0;
}
