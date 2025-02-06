#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1,str2,str;
  int i=0;
  cout<<"Введите первую строку: \n";
  getline(cin, str1);
  cout<<"Введите вторую строку \n";
  getline(cin, str2);
  if(str1.length()>str2.length())
  {
    str=str1;
    str1=str2;
    str2=str;
  }
  cout<<"Общая подстрока: ";
  while(i<str1.length())
  {
    for(int j=i; j<str2.length(); j++)
      if(str1[i]==str2[j])
      {
        cout<<str1[i];
        break;
      }
    i++;
  }
cout<<endl;
}
