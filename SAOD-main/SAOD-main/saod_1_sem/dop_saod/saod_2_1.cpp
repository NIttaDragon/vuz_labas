#include <iostream>
#include <string>
using namespace std;

int main()
{
  string str1="18";
  string str2="23";
  string str3;
  int d=0;
  for(int i=0;i<str2.length();i++)
  {
    int a=int(str1[i]);
    int b=int(str2[i]);
    int c=a+b;
    if(c>10)
    {
      d=c%10;
      c=1;
    }
    if(i==0)
    {
      str3[i]=to_string(d);
    }
    else
    {
      str3[i]=to_string(d+c);
    }
  }
  cout<<str3<<endl;
}
