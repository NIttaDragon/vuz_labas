#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
  int i,len;
  char tmp[80];
  char* str;
  do
  {
    cout<<"Введите строку: "<<endl;
    cin.getline(tmp,80);
    len=strlen(tmp)+1;
    str=new char[len];
    strncpy(str,tmp,len);
    if (ispunct(tmp[len-2]))
    {
      cout<<"Перевернутая строка: "<<endl;
      for(i=(len-2);i>=0;i--)
      {
        cout<<(*(str+i));
      }
      cout<<endl;
    }
    else
    {
      cout<<"Введенный текст не удовлетворяет параметрам ввода"<<endl;
      return 0;
    }
    delete []str;
  }while(ispunct(tmp[len-2]));
}
