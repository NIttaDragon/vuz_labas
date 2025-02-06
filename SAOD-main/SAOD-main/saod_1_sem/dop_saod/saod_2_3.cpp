#include <iostream>
using namespace std;

int main()
{
  int str1[209];
  int str2[209];
  int str3[209];
  int str4[209];
  for(int i=0;i<209;i++)
  {
    str1[i]=0;
    str2[i]=0;
    str3[i]=0;
    str4[i]=0;
  }
  str1[0]=1;
  str2[0]=2;
  int d;
  int k=0;
  int c;
  for(int j=3;j<10;j++)
  {
    k=0;
    for(int i=0;i<209;i++)
    {
      if(i==0)
      {
        c=str1[i]+str2[i];
        if(c>9)
        {
          d=c%10;
          k=1;
          str3[i]=d;
          d=0;
        }
        else
        {
          str3[i]=c;
          c=0; k=0;
        }
      }
      else
      {
        c=str1[i]+str2[i]+k;
        if(c>9)
        {
          d=c%10;
          k=1;
          str3[i]=d;
          d=0;
        }
        else
        {
          str3[i]=c;
          c=0; k=0;
        }
      }
    }
    for(int i=0;i<209;i++)
    {
      str1[i]=str2[i];
      str2[i]=str3[i];
    }
  }
  for(int i=0;i<209;i++)
  {
    str4[i]=str3[208-i];
    cout<<str4[i];
  }
  cout<<endl;
}
