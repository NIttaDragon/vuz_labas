#include <iostream>
using namespace std;

int main()
{
  int num;
  int k1=0; int k2=0; int k3=0;
  char a;
  cout<<"Введите длину строки"<<endl;
  cin>>num;
  string *s = new string[num];
  cout<<"Заполните строку посимвольно"<<endl;
  for(int i=0;i<num;i++)
  {
    cin>>a;
    s[i] = a;
    if(a=='[' | a==']' | a=='(' | a==')' | a=='{' | a=='}')
    {
      if(a=='{')
        k1=1;
      if(a=='(')
        k2=1;
      if(a=='[')
        k3=1;
      if(a=='}')
      {
        if(k1==0)
        {
          cout<<"Ошибка ввода {}"<<endl;
          break;
        }
        if(k2==0 && k3==0)
          k1=0;
        else
        {
          cout<<"Ошибка ввода {}"<<endl;
          break;
        }
      }
      if(a==')')
      {
        if(k2==0)
        {
          cout<<"Ошибка ввода {}"<<endl;
          break;
        }
        if(k1==0 && k3==0)
          k2=0;
        else
        {
          cout<<"Ошибка ввода {}"<<endl;
          break;
        }
      }
      if(a==']')
      {
        if(k3==0)
        {
          cout<<"Ошибка ввода {}"<<endl;
          break;
        }
        if(k2==0 && k1==0)
          k3=0;
        else
        {
          cout<<"Ошибка ввода {}"<<endl;
          break;
        }
      }
    }
  }
  delete [] s;
  return 0;
}
