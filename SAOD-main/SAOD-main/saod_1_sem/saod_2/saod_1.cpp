#include <iostream>
using namespace std;

int main()
{
  int num,a,b;
  cout<<"Введите размер стека"<<endl;
  cin>>num;
  int *s = new int[num];
  cout<<"Заполните стек данными"<<endl;
  for (int h=0;h<num;h++)
  {
    int a;
    cin>>a;
    s[h] = a;
  }
  int k=1;
  cout<<"Что хотите сделать со стеком"<<endl;
  while(k!=0)
  {
    cout<<"1. Добавить элемент в стек"<<endl;
    cout<<"2. Вывести стек на экран"<<endl;
    cout<<"3. Забрать элемент из стека"<<endl;
    cout<<"4. Выйти из программы"<<endl;
    cin>>a;
    switch(a)
    {
      case 1:
      {
        num++;
        int *s1 = new int[num];
        for(int i = 1;i<num;i++)
          s1[i]=s[i-1];
        cout<<"Введите значение"<<endl;
        cin>>a;
        s1[0]=a;
        delete [] s;
        int *s = new int[num];
        for(int i =0;i<num;i++)
          s[i]=s1[i];
        delete [] s1;
        break;
      }
      case 2:
      {
        for(int i=0;i<num;i++)
          cout<<s[i]<<", ";
        cout<<endl;
        break;
      }
      case 3:
      {
        num--;
        int *s1 = new int[num];
        //cout<<s[0]<<endl;
        for(int i =1;i<num+1;i++)
          s1[i-1]=s[i];
        delete [] s;
        int *s = new int[num];
        for(int i =0;i<num;i++)
          s[i]=s1[i];
        delete [] s1;
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
