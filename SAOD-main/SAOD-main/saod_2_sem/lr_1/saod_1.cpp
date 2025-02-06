#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int i, j;
  int k=0;
  string str1 = "bcaaabcccababbccaccccabbcacbcaabcccbccbbaacababcaccabaaaccccabbcbcbaccccbbcbbbabccbccbaacbcabccacaca";
  string str2 = "abc";
  // string str1,str2;
  // cout<<"Введите строку: \n";
  // getline(cin, str1);
  // cout<<"Введите подстроку \n";
  // getline(cin, str2);
  for(i = 0; i<str1.length()+1; i++)
  {
    for(j = 0; j<str2.length()+1; j++)
      if (str1[i+j] != str2[j])
        break;
    if (j == str2.length())
    {
      cout<<"Начало подстроки: "<<i<<endl;
      k++;
    }
  }
  if (k==0) cout<<"Подстрока не найдена \n";
}
