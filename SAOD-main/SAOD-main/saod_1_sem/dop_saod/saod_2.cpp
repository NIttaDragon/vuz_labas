# include <iostream>
#include <ostream.h>
#include <cmath>
using namespace std;

int main()
{
  unsigned long long int a[1000];
  int i;
  a[0]=1;
  a[1]=2;
  for (i=2;i<1000;i++)
    {
      a[i]=a[i-1]+a[i-2];
      ostringstream stream;
      stream<<a[i];
      string converted = stream.str();
      //cout<<a[i]<<endl;

    }
  //cout<<a[1000]<<endl;
}
