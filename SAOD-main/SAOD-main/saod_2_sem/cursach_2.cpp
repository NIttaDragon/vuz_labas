//файл ansi
//код windows 1251 или cp866

#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>
#include <windows.h>

using namespace std;

ifstream file;  //поток для чтения файла
unsigned long int hash_chisl = 1661939;
unsigned long int avt_hash_chisl = time(NULL) % hash_chisl;

int hash_alf(string vspom_strok) //хеш-функция по первой букве строки
{
  unsigned long int hash_ind = 0;
  hash_ind = vspom_strok[0];
  return hash_ind % hash_chisl;
}

int hash_buk(string vspom_strok, bool bukv_flag) //хеш-функция по количеству гласных или согласных букв в слове
{
  int kol_glas = 0, kol_sogl = 0;
  for(int j = 0; j < vspom_strok.length(); j++)
  {
    if((vspom_strok[j] == 'А') or (vspom_strok[j] == 'а') or (vspom_strok[j] == 'Е') or
    (vspom_strok[j] == 'е') or (vspom_strok[j] == 'Ё') or (vspom_strok[j] == 'ё') or
    (vspom_strok[j] == 'И') or (vspom_strok[j] == 'и') or (vspom_strok[j] == 'О') or
    (vspom_strok[j] == 'о') or (vspom_strok[j] == 'У') or (vspom_strok[j] == 'у') or
    (vspom_strok[j] == 'ы') or (vspom_strok[j] == 'Э') or (vspom_strok[j] == 'э') or
    (vspom_strok[j] == 'Ю') or (vspom_strok[j] == 'ю') or (vspom_strok[j] == 'Я') or (vspom_strok[j] == 'я'))
      kol_glas++;
    else
      kol_sogl++;
  }
  if (!bukv_flag)
    return kol_glas % hash_chisl;
  else
    return kol_sogl % hash_chisl;
}

int hash_avt(string vspom_strok) //хеш-функция для авторского хеширования
{
  unsigned long long int hash_ind = 0;
  for(int j = 0; j < vspom_strok.length(); j++)
    hash_ind += vspom_strok[j] * avt_hash_chisl * (j + 1) * vspom_strok[j-1];
  return hash_ind % hash_chisl;
}

int main()
{
  setlocale(LC_ALL, "");
  int nominal = 701, file_ind = 0, switch_1, switch_2, switch_3, vspom_int, hash_int;
  float kol_colis; //количество коллизий
  int alf_arr[nominal]; // массив для хеша по первой букве (701 - лишний)
  int buk_arr[nominal]; // массив для хеша по количеству согласных / гласных (701 - лишний)
  int avt_arr[nominal]; // массив для хеша по количеству согласных / гласных (701 - лишний)
  string vspom_strok, hash_strok; // строка для чтения из файла
  string osn_strok [nominal];  // массив строк из файла
  clock_t start, stop;
  file.open("text3.txt"); // открытие файла

  while (!file.eof()) // чтение данных из файла
  {
    file>>vspom_strok;
    osn_strok[file_ind] = vspom_strok;
    file_ind++;
  }

  file.close(); // закрытие файла

  bool er_flag, bukv_flag, kol_sovp;
  system("cls");
  while(true)
  {
    cout<<"Что вы хотите сделать:\n";
    cout<<"1.Сортировка по алфавиту\n";
    cout<<"2.Поиск слова в словаре\n";
    cout<<"3.Завершить программу\n";
    cin>>switch_1;
    switch(switch_1)
    {
      case 1: //сортировка по алфавиту
        for (int i = 0; i < nominal - 1; i++)
          for (int j=0; j < nominal - 2; j++)
            if (osn_strok[j] > osn_strok[j+1])
            {
              vspom_strok = osn_strok[j];
              osn_strok[j] = osn_strok[j+1];
              osn_strok[j+1] = vspom_strok;
            }
        for (int i = 0; i < nominal - 1; i++)
            cout<<osn_strok[i]<<endl;
        break;
      case 2: //поиск по слову
        cout<<"Введите слово, которое хотите найти:\n";
        cin>>vspom_strok;
        for (int i=0; i<vspom_strok.length(); i++)  //перекодировка входных букв в кодировку файла
        {
          if (vspom_strok[i] =='с')
            vspom_strok[i] = 'ё';
          else if (vspom_strok[i] =='р')
            vspom_strok[i] = 'Ё';
          else if (vspom_strok[i] >='а')
            vspom_strok[i] += 16;
          else
            vspom_strok[i] = vspom_strok[i] + 64;
        }
        cout<<"Какое хеширование вы хотите использовать для поиска слова:\n";
        cout<<"1.Хеширование по первой букве алфавита\n";
        cout<<"2.Хеширование по числу глассных и числу согласных букв в словах\n";
        cout<<"3.Авторское хеширование\n";
        cout<<"4.Обратно в меню\n";
        cin>>switch_3;
        switch(switch_3)
        {
          case 1: //хеширование по первой букве слова
            start = clock();
            hash_int = hash_alf(vspom_strok);
            hash_strok = vspom_strok;
            for (int i = 0; i < nominal - 1; i++)
            {
              vspom_strok = osn_strok[i];
              alf_arr[i] = hash_alf(vspom_strok);
            }
            for(int i=0;i<nominal-1;i++)
              if((hash_int == alf_arr[i]) and (hash_strok == osn_strok[i]))
                kol_sovp=1;
            Sleep(3);
            stop = clock();
            cout<<"time =" <<stop-start<<endl;
            break;
          case 2: //хеширование числу гласных или согласных букв в слове
            er_flag = true;
            while(er_flag)
            {
              cout<<"По каким буквам вы хотите сделать хеширование"<<endl;
              cout<<"1. По глассным"<<endl;
              cout<<"2. По соглачным"<<endl;
              cin>>switch_2;
              switch (switch_2)
              {
                case 1:
                  bukv_flag = 0;
                  er_flag = 0;
                  break;
                case 2:
                  bukv_flag= 1;
                  er_flag = 0;
                  break;
                default:
                  cout<<"Введено неверное значение"<<endl;
                  break;
              }
            }
            start = clock();
            hash_int = hash_buk(vspom_strok, bukv_flag);
            for (int i = 0; i < nominal - 1; i++)
            {
              vspom_strok = osn_strok[i];
              buk_arr[i] = hash_buk(vspom_strok, bukv_flag);
            }
            for(int i=0;i<nominal-1;i++)
              if((hash_int == buk_arr[i]) and (hash_strok == osn_strok[i]))
                kol_sovp=1;
            Sleep(3);
            stop = clock();
            cout<<"time = "<<stop - start<<endl;
            break;
          case 3: //авторское хеширование
            start = clock();
            hash_int = hash_avt(vspom_strok);
            kol_colis = 0;
            for (int i = 0; i < nominal - 1; i++)
            {
              vspom_strok = osn_strok[i];
              avt_arr[i] = hash_avt(vspom_strok);
            }
            for(int i=0;i<nominal-1;i++)
              if((hash_int == avt_arr[i]) and (hash_strok == osn_strok[i]))
                kol_sovp=1;
            Sleep(3);
            stop = clock();
            cout<<"time = "<<stop - start<<endl;
            for (int i = 0; i < nominal - 1; i++)
              if ((avt_arr[i] == avt_arr[i+1]) && (osn_strok[i] != osn_strok[i+1]))
                kol_colis++;
            cout<<"Коллизия составляет: "<<kol_colis / 700 * 100<<"%"<<endl;
            break;
          case 4:
            break;
        }
        if (!kol_sovp)
          cout<<"Совпадений не найдено\n";
        else
          cout<<"Слово найдено\n";
        kol_sovp = 0;
        break;
      case 3: //завершение программы
        return 0;
        break;
      default:
        cout<<"Введено неверное значение"<<endl;
        break;
    }
  }
  return 0;
}
// должно быть примерно 1, 3, 2
