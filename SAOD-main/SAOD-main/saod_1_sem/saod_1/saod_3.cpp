#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  int i,k,n;
  for(i=1000;i<10000;i=i+1000)
  {
    int const len=i;
    int a[len];
    unsigned int start_time=clock();
    for(k=0;k<len;k++)
    {
      a[k]=rand()%1000;
    }
    int l=1;
    while(l!=0)
    {
      l=0;
      for (k=1;k<len;k++)
      {
        if(a[k-1]>a[k])
        {
          n=a[k-1];
          a[k-1]=a[k];
          a[k]=n;
          l++;
        }
      }
    }
    unsigned int end_time=clock();
    unsigned int search_time=end_time-start_time;
    cout<<"затраченное время в милисекундах: "<<search_time<<endl;
  }
}
