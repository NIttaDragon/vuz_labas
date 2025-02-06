#include <iostream>
using namespace std;

int main()
{
  int num,a;
  int k=0;
  cout<<"Введите количество участников"<<endl;
  cin>>num;
  int *s = new int[num];
  for(int i=0;i<num;i++)
  {
    s[i]=i;
  }
  for(int i=0;i<num-1;i++)
  {
    cout<<"Введите номер выбывающего"<<endl;
    cin>>a;
    while(k<a)
    {
      if(k=a)
        s[k]=0;
      if(s[k]!=0)
        k++;
    }
    k=0;
  }
  cout<<"Оставшийся участник"<<endl;
  for(int i=0;i<num;i++)
    if(s[i]!=0)
      cout<<s[i]<<endl;
  delete [] s;
  return 0;
}
