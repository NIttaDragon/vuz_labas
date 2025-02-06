#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int i, j;
  string str1 = "bcaaabcccababbccaccccabbcacbcaabcccbccbbaacababcaccabaaaccccabbcbcbaccccbbcbbbabccbccbaacbcabccacaca";
  string str2 = "abc";
  //cout<<"Введите строку: \n";
  //getline(cin, str1);
  //cout<<"Введите подстроку \n";
  //getline(cin, str2);
  int *a = new int [str2.length()];
  for (i=0;i<str2.length();i++)
    a[i] = 0;
  i = 1; j = 0;
  while (i < str2.length())
  {
    if(str2[i] != str2[j])
    {
      if(j == 0)
      {
        a[i] = 0;
        i++;
      }
      else j = a[j-1];
    }
    else
    {
      a[i] = j+1;
      i++; j++;
    }
  }
  i = 0; j = 0;
  while (i < str1.length()-str2.length()+1)
  {
    if(str1[i] == str2[j])
    {
      i++; j++;
      if(j == str2.length()) cout<<"Начало подстроки: "<<i-str2.length()<<endl;
    }
    else
    {
      if(j > 0) j = a[j-1];
      else i++;
    }
  }
}
