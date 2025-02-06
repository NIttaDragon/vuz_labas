#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double strhashing(string str)
{
  hash<string> hash_obj;
  return hash_obj(str);
}

int main()
{
  double hash1, hash2;
  string str, str1, str2;
  int i = 0; int k = 0; int l;
  cout<<"Введите строку \n";
  getline(cin,str1);
  cout<<"Введите подстроку \n";
  getline(cin, str2);
  hash2 = strhashing(str2);
  while (i < str1.length()-str2.length()+1)
  {
    str.clear();
    str.append(str1,i,str2.length());
    hash1 = strhashing(str);
    if (hash1 == hash2)
    {
      l = 0;
      for (int j = 0; j < str2.length(); j++)
        if (str[j] == str2[j]) l++;
      if (l == str2.length())
        cout<<"Начало подстроки: "<<i<<endl;
      k++;
    }
    i++;
  }
  if(k == 0)
    cout<<"Строка не содержит подстроку \n";
}
