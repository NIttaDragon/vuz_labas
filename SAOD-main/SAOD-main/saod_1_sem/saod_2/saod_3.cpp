#include <iostream>
#include "saod3.1.cpp"
using namespace std;

int main()
{
  list l;
  int a,k,num;
  cout<<"Сколько чисел вы хотите добавить в список"<<endl;
  cin>>num;
  cout<<"Введите числа, которое хотите добавить в список"<<endl;
  for(int i=0;i<num;i++)
  {
    cin>>a;
    l.back(a);
  }
  while(k!=0)
  {
    cout<<"Что хотите сделать со списком"<<endl;
    cout<<"1. Добавть элемент в конец списка"<<endl;
    cout<<"2. Вывести список на экран"<<endl;
    cout<<"3. Удалить последний элемент"<<endl;
    cout<<"4. Удалить первый элемент"<<endl;
    cout<<"5. Удалить выбранное значение"<<endl;
    cout<<"6. Выйти из программы"<<endl;
    cin>>a;
    switch(a)
    {
      case 1:
        cout<<"Введите значение"<<endl;
        cin>>a;
        l.back(a);
        break;
      case 2:
        l.print();
        break;
      case 3:
        l.r_first();
        break;
      case 4:
        l.r_last();
        break;
      case 5:
        cout<<"Введите значение"<<endl;
        cin>>a;
        l.remove(a);
        break;
      case 6:
        k=0;
        break;
    }
  }
  return 0;
}
