#include <iostream>
#include <cstring>
using namespace std;

int main()
{
  int i, n, kol, j, net, groups, dvas;
  struct kurs
  {
    char inic[40];
    int group;
    int mark[5];
    int dva;
  };
  cout<<"Введите количество людей"<<endl;
  cin>>n;
  kurs* box= new kurs[n];
  kurs tmp;

  for(int i=0;i<n;i++) //заполнение данных
    {
      kol=0;
      cout<<endl;
      cout<<"Введите фамилию и инициалы в формате Фамилия.И.О: "<<endl;
      cin.getline(box[i].inic,80);
      cin >> box[i].inic;
      cout<<"Введите номер группы: "<<endl;
      cin>>box[i].group;
      cout<<"Введите оценки: "<<endl;
      for(j=0;j<5;j++)
      {
        cin>>box[i].mark[j];
        if (box[i].mark[j]=='2')
          kol++;
        box[i].dva=kol;
      }
    }
  char inics[40];
  for (i=n-1;i>0;i--)//сортировка
  {
    for(int j=0;j<i;j++)
    {
      if(strcmp(box[j].inic,box[j+1].inic)>0)
      {
        strcpy(inics,box[j].inic);
        strcpy(box[j].inic,box[i].inic);
        strcpy(box[i].inic,inics);
        groups=box[i].group;
        box[i].group=box[j].group;
        box[j].group=groups;
        dvas=box[i].dva;
        box[i].dva=box[j].dva;
        box[j].dva=groups;
      }
    }
  }
  cout<<endl;
  cout<<"Сортировка по алфавиту: "<<endl;
  for(int i=0;i<n;i++) //вывод на экран студентов
  {
    cout<<"Фамилия и инициалы: "<<box[i].inic<<endl;
    cout<<"Номер группы: "<<box[i].group<<endl;
  }
  cout<<endl;
  cout<<"Неуспевающие студенты: "<<endl;
  net=0;
  for(i=0;i<n;i++)
  {
    if(box[i].dva>2)
    {
      cout<<"Фамилия и инициалы: "<<box[i].inic<<endl;
      cout<<"Номер группы: "<<box[i].group<<endl;
    }
    else net++;
  }
  if(net==n) cout<<"Таких студентов нет"<<endl;
  return 0;
}
