#include <iostream>
using namespace std;

struct Uzel //реализация узла
{
  int variab;
  Uzel* next;
  Uzel(int _variab):variab(_variab), next(nullptr){}
};

struct list //реализация списка
{
  Uzel* first;
  Uzel* last;
  list():first(nullptr), last(nullptr){}

  bool is_empty() //присутстсвие узла в списке
  {
    return first==nullptr;
  }

  void back(int _variab) //добавление узла в конец списка
  {
    Uzel* point = new Uzel(_variab);
    if(is_empty())
    {
      first = point;
      last = point;
      return;
    }
    last->next = point;
    last = point;
  }

  void r_first() //удаление первого узла
  {
    if (is_empty())
      return;
    Uzel* point =first;
    first = point->next;
    delete point;
  }

  void r_last() //удаление последнего узла
  {
    if(is_empty())
      return;
    if(first == last)
    {
      r_first();
      return;
    }
    Uzel* point = first;
    while(point->next != last)
      point = point->next;
    point->next = nullptr;
    delete last;
    last = point;
  }

  void remove(int _variab) //удаление узла по значению
  {
    if(is_empty())
      return;
    if(first->variab == _variab)
    {
      r_first();
      return;
    }
    else if(last->variab == _variab)
    {
      r_last();
      return;
    }
    Uzel* slow = first;
    Uzel* fast = first->next;
    while(fast && fast->variab != _variab)
    {
      fast= fast->next;
      slow = slow->next;
    }
    if(!fast)
    {
      cout<<"Такого элемента не существует"<<endl;
      return;
    }
    slow->next = fast->next;
    delete fast;
  }

  void print() //вывод списка на экран
  {
    if(is_empty())
    {
      cout<<"Список пуст"<<endl;
      return;
    }

    Uzel* point = first;
    while (point)
    {
      cout<<point->variab<<" ";
      point=point->next;
    }
    cout<<endl;
  }
};
