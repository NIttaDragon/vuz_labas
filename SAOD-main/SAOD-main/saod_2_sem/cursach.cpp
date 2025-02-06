//файл ansi
//код windows 1251 или cp866

#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>

using namespace std;
ifstream file;  //поток для чтения файла
unsigned long int p = 1661939;
unsigned long int ra = time(NULL)%p;

int hash_alf(string s)
{
  unsigned long int i = 0;
  i=s[0];
  return i%p;
}

int hash_buk(string s, bool k)
{
  unsigned long int i = 0;
  int kg = 0, ks = 0;
  char ch;
  for(int j = 0; j<s.length(); j++)
  {
    ch=s[j];
    //переделать в ифелс
    switch(ch)
    {
      case 'А':
        kg++;
        break;
      case 'а':
        kg++;
        break;
      case 'Б':
        ks++;
        break;
      case 'б':
        ks++;
        break;
      case 'В':
        ks++;
        break;
      case 'в':
        ks++;
        break;
      case 'Г':
        ks++;
        break;
      case 'г':
        ks++;
        break;
      case 'Д':
        ks++;
        break;
      case 'д':
        ks++;
        break;
      case 'Е':
        kg++;
        break;
      case 'е':
        kg++;
        break;
      case 'Ё':
        kg++;
        break;
      case 'ё':
        kg++;
        break;
      case 'Ж':
        ks++;
        break;
      case 'ж':
        ks++;
        break;
      case 'З':
        ks++;
        break;
      case 'з':
        ks++;
        break;
      case 'И':
        kg++;
        break;
      case 'и':
        kg++;
        break;
      case 'Й':
        ks++;
        break;
      case 'й':
        ks++;
        break;
      case 'К':
        ks++;
        break;
      case 'к':
        ks++;
        break;
      case 'Л':
        ks++;
        break;
      case 'л':
        ks++;
        break;
      case 'М':
        ks++;
        break;
      case 'м':
        ks++;
        break;
      case 'Н':
        ks++;
        break;
      case 'н':
        ks++;
        break;
      case 'О':
        kg++;
        break;
      case 'о':
        kg++;
        break;
      case 'П':
        ks++;
        break;
      case 'п':
        ks++;
        break;
      case 'Р':
        ks++;
        break;
      case 'р':
        ks++;
        break;
      case 'С':
        ks++;
        break;
      case 'с':
        ks++;
        break;
      case 'Т':
        ks++;
        break;
      case 'т':
        ks++;
        break;
      case 'У':
        kg++;
        break;
      case 'у':
        kg++;
        break;
      case 'Ф':
        ks++;
        break;
      case 'ф':
        ks++;
        break;
      case 'Х':
        ks++;
        break;
      case 'х':
        ks++;
        break;
      case 'Ц':
        ks++;
        break;
      case 'ц':
        ks++;
        break;
      case 'Ш':
        ks++;
        break;
      case 'ш':
        ks++;
        break;
      case 'Щ':
        ks++;
        break;
      case 'щ':
        ks++;
        break;
      case 'ъ':
        ks++;
        break;
      case 'ы':
        kg++;
        break;
      case 'ь':
        ks++;
        break;
      case 'Э':
        kg++;
        break;
      case 'э':
        kg++;
        break;
      case 'Ю':
        kg++;
        break;
      case 'ю':
        kg++;
        break;
      case 'Я':
        kg++;
        break;
      case 'я':
        kg++;
        break;
    }
  }
  if (!k)
    return kg%p;
  else
    return ks%p;
}

int hash_avt(string s)
{
  unsigned long long int i = 0;
  for(int j = 0; j<s.length(); j++)
    i+=s[j]*ra*(j+1)*s[j-1];
  return i%p;
}

int main()
{
  setlocale(LC_ALL, "");
  int n = 701, v = 0, a, b, e;
  float col;
  int alf_arr[n]; // массив для хеша по первой букве (701 - лишний)
  int buk_arr[n]; // массив для хеша по количеству согласных / гланых (701 - лишний)
  int avt_arr[n]; // массив для хеша по количеству согласных / гланых (701 - лишний)
  string s, d; // строка для чтения из файла
  string strt [n];  // массив строк из файла

  file.open("text3.txt"); // открытие файла

  while (!file.eof()) // чтение данных из файла
  {
    file>>s;
    strt[v] = s;
    v++;
  }

  file.close(); // закрытие файла

  bool t, k, kol;
  // system("cls");
  while(true)
  {
    cout<<"Что вы хотите сделать:\n";
    cout<<"1.Хеширование по первой букве алфавита\n";
    cout<<"2.Хеширование по числу глассных и числу согласных букв в словах\n";
    cout<<"3.Авторское хеширование\n";
    cout<<"4.Сортировка по алфавиту\n";
    cout<<"5.Поиск слова в словаре\n";
    cout<<"6.Завершить программу\n";
    cin>>a;
    switch(a)
    {
      case 1: //хеширование по первой букве слова
        for(int i = 0; i<n-1; i++)
        {
          s = strt[i];
          alf_arr[i] = hash_alf(s);
        }
        for(int i=0; i<n-1; i++)
          for(int j=1; j<n-1; j++)
          {
            if(alf_arr[j]<alf_arr[j-1])
            {
              e = alf_arr[j-1];
              alf_arr[j-1] = alf_arr[j];
              alf_arr[j] = e;
              d = strt[j-1];
              strt[j-1] = strt[j];
              strt[j] = d;
            }
          }
        for(int i = 0; i<n-1; i++)
            cout<<alf_arr[i]<<" "<<strt[i]<<endl;
        break;
      case 2: //хеширование числу гласных или согласных
        t = true;
        while(t)
        {
          cout<<"По каким буквам вы хотите сделать хеширование"<<endl;
          cout<<"1. По глассным"<<endl;
          cout<<"2. По соглачным"<<endl;
          cin>>b;
          switch (b)
          {
            case 1:
              k = 0;
              t = 0;
              break;
            case 2:
              k = 1;
              t = 0;
              break;
            default:
              cout<<"Введено неверное значение"<<endl;
              break;
          }
        }
        for(int i = 0; i<n-1; i++)
        {
          s = strt[i];
          buk_arr[i] = hash_buk(s, k);
        }
        for(int i=0; i<n-1; i++)
          for(int j=1; j<n-1; j++)
          {
            if(buk_arr[j]<buk_arr[j-1])
            {
              e = buk_arr[j-1];
              buk_arr[j-1] = buk_arr[j];
              buk_arr[j] = e;
              d = strt[j-1];
              strt[j-1] = strt[j];
              strt[j] = d;
            }
          }
        for(int i = 0; i<n-1; i++)
            cout<<buk_arr[i]<<" "<<strt[i]<<endl;
        break;
      case 3: //авторское хеширование
        col=0;
        for(int i = 0; i<n-1; i++)
        {
          s = strt[i];
          avt_arr[i] = hash_avt(s);
        }
        for(int i=0; i<n-1; i++)
          for(int j=1; j<n-1; j++)
          {
            if(avt_arr[j]<avt_arr[j-1])
            {
              e = avt_arr[j-1];
              avt_arr[j-1] = avt_arr[j];
              avt_arr[j] = e;
              d = strt[j-1];
              strt[j-1] = strt[j];
              strt[j] = d;
            }
          }
        for(int i = 0; i<n-1; i++)
        {
          cout<<avt_arr[i]<<" "<<strt[i]<<endl;
          if((avt_arr[i] == avt_arr[i+1])&&(strt[i]!=strt[i+1]))
            col++;
        }
        cout<<"Коллизия составляет: "<<col/700*100<<"%"<<endl;
        break;
      case 4: //сортировка по алфавиту
        for(int i=0;i<n-1;i++)
          for(int j=0;j<n-2;j++)
            if(strt[j]>strt[j+1])
            {
              d = strt[j];
              strt[j] = strt[j+1];
              strt[j+1] = d;
            }
        for(int i = 0; i<n-1; i++)
            cout<<strt[i]<<endl;
        break;
      case 5: //поиск по слову
        cout<<"Введите слово, которое хотите найти:\n";
        cin>>s;
        for(int i=0;i<s.length();i++)
        {
          if(s[i]=='с')
            s[i] = 'ё';
          else if(s[i] =='р')
            s[i] = 'Ё';
          else if(s[i]>='а')
            s[i]+=16;
          else
            s[i] = s[i]+64;
        }
        // cout<<s<<endl;
        for(int i=0;i<n-1;i++)
          if(strt[i]==s)
          {
            cout<<"Совпадение найдено по номеру "<<i+1<<endl;
            kol=1;
          }
        if(!kol)
          cout<<"Совпадений не найдено\n";
        kol=0;
        break;
      case 6: //завершение программы
        return 0;
        break;
      default:
        cout<<"Введено неверное значение"<<endl;
        break;
    }
  }
  return 0;
}
