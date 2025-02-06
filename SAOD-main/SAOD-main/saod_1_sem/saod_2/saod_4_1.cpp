#include <iostream>
using namespace std;

struct node
{
  int info;
  node *l,*r;
};

void push(int a,node** t)
{
  if((*t)==NULL)
  {
    (*t)=new node;
    (*t)->info=a;
    (*t)->l=(*t)->r=NULL;
    return;
  }
  if(a>(*t)->info)
    push(a,&(*t)->r);
  else
    push(a, &(*t)->l);
}

void print(node* t,int u)
{
  if(t==NULL)
    return;
  else
  {
    print(t->l,++u);
    cout<<t->info<<"|";
    u--;
  }
  print(t->r,++u);
}

int main()
{
  int n,val;
  cout<<"Введите количество элементов дерева"<<endl;
  cin>>n;
  node* root=NULL;
  cout<<"Введите элементы"<<endl;
  for(int i=0;i<n;i++)
  {
    cin>>val;
    push(val, &root);
  }
  cout<<"Построенное дерево"<<endl;
  print(root, n);
  cout<<endl;
  return 0;
}
