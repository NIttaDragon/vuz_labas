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
  int d=0;
  int k=0;
  for(int j=3;j<1001;j++)
  {
    for(int i=0;i<209;i++)
    {
      int c=str1[i]+str2[i];
      if(c>=10)
      {
        d=c%10;
        if(i==0)
        {
          str3[i]=d;
          d=0;
        }
        else
        {
          str3[i]=d+k;
          d=0; k=0;
        }
        k=1;
      }
      else
      {
        d=c;
        if(i==0)
        {
          str3[i]=d;
          d=0;
        }
        else
        {
          str3[i]=d+k;
          d=0; k=0;
        }
      }
    }
    for(int i=0;i<209;i++)
    {
      str1[i]=str2[i];
      str2[i]=str3[i];
    }
    for(int i=0;i<209;i++)
    {
      str4[i]=str3[208-i];
      cout<<str4[i];
    }
    cout<<endl;
    cout<<j;
    cout<<endl;
    int a;
    //cin>>a;
  }

  /*for(int i=0;i<209;i++)
  {
    str4[i]=str3[208-i];
    cout<<str4[i];
  }
cout<<endl;*/
}
