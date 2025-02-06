//ä ©« ˘ ansi
//Ş®¤ ˘ windows 1251 | cp866

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream file;  //Ż®â®Ş ¤«ď çâĄ­¨ď ä ©« 

int main()
{
  setlocale(LC_ALL, "");
  int n = 700, k = 0;
  char arra[n][20]; //¬ áá¨˘ á«®˘
  int arr[700][1]; //¬ áá¨˘ ¤«ď ĺĄč 
  for (int i = 0;i<700; i++)
    arr[i][0]=0;
  string s; //áâŕ®Ş  ¤«ď çâĄ­¨ď ¨§ ä ©« 

  file.open("text3.txt"); //®âŞŕëâ¨Ą ä ©« 

  while (!file.eof()) //çâĄ­¨Ą ¤ ­­ëĺ ¨§ ä ©« 
  {
    file>>s;
    cout<<s<<endl;
    for(int i =0;i<20;i++)
      arra[k][i] = '\0';
    for(int i=0;i<s.length();i++)
    {
      arra[k][i] = s[i];
      cout<<arra[k][i]<<endl;
    }
    k++;
  }
  cout << endl;

  for(int i = 0; i<700;i++)
    for(int j = 0; j<20; j++)
    {
      switch(arra[i][j])
      {
        case '€':
          arr[i][0] = arr[i][0] + 1;
          break;
        case ' ':
          arr[i][0] = arr[i][0] + 2;
          break;
        case '':
          arr[i][0] = arr[i][0] + 3;
          break;
        case 'ˇ':
          arr[i][0] = arr[i][0] + 4;
          break;
        case '‚':
          arr[i][0] = arr[i][0] + 5;
          break;
        case '˘':
          arr[i][0] = arr[i][0] + 6;
          break;
        case '':
          arr[i][0] = arr[i][0] + 7;
          break;
        case 'Ł':
          arr[i][0] = arr[i][0] + 8;
          break;
        case '„':
          arr[i][0] = arr[i][0] + 9;
          break;
        case '¤':
          arr[i][0] = arr[i][0] + 10;
          break;
        case '…':
          arr[i][0] = arr[i][0] + 11;
          break;
        case 'Ą':
          arr[i][0] = arr[i][0] + 12;
          break;
        case 'đ':
          arr[i][0] = arr[i][0] + 13;
          break;
        case 'ń':
          arr[i][0] = arr[i][0] + 14;
          break;
        case '†':
          arr[i][0] = arr[i][0] + 15;
          break;
        case '¦':
          arr[i][0] = arr[i][0] + 16;
          break;
        case '‡':
          arr[i][0] = arr[i][0] + 17;
          break;
        case '§':
          arr[i][0] = arr[i][0] + 18;
          break;
        case '':
          arr[i][0] = arr[i][0] + 19;
          break;
        case '¨':
          arr[i][0] = arr[i][0] + 20;
          break;
        case '‰':
          arr[i][0] = arr[i][0] + 21;
          break;
        case '©':
          arr[i][0] = arr[i][0] + 22;
          break;
        case 'Š':
          arr[i][0] = arr[i][0] + 23;
          break;
        case 'Ş':
          arr[i][0] = arr[i][0] + 24;
          break;
        case '‹':
          arr[i][0] = arr[i][0] + 25;
          break;
        case '«':
          arr[i][0] = arr[i][0] + 26;
          break;
        case 'Ś':
          arr[i][0] = arr[i][0] + 27;
          break;
        case '¬':
          arr[i][0] = arr[i][0] + 28;
          break;
        case 'Ť':
          arr[i][0] = arr[i][0] + 29;
          break;
        case '­':
          arr[i][0] = arr[i][0] + 30;
          break;
        case 'Ž':
          arr[i][0] = arr[i][0] + 31;
          break;
        case '®':
          arr[i][0] = arr[i][0] + 32;
          break;
        case 'Ź':
          arr[i][0] = arr[i][0] + 33;
          break;
        case 'Ż':
          arr[i][0] = arr[i][0] + 34;
          break;
        case '':
          arr[i][0] = arr[i][0] + 35;
          break;
        case 'ŕ':
          arr[i][0] = arr[i][0] + 36;
          break;
        case '‘':
          arr[i][0] = arr[i][0] + 37;
          break;
        case 'á':
          arr[i][0] = arr[i][0] + 38;
          break;
        case '’':
          arr[i][0] = arr[i][0] + 39;
          break;
        case 'â':
          arr[i][0] = arr[i][0] + 40;
          break;
        case '“':
          arr[i][0] = arr[i][0] + 41;
          break;
        case 'ă':
          arr[i][0] = arr[i][0] + 42;
          break;
        case '”':
          arr[i][0] = arr[i][0] + 43;
          break;
        case 'ä':
          arr[i][0] = arr[i][0] + 44;
          break;
        case '•':
          arr[i][0] = arr[i][0] + 45;
          break;
        case 'ĺ':
          arr[i][0] = arr[i][0] + 46;
          break;
        case '–':
          arr[i][0] = arr[i][0] + 47;
          break;
        case 'ć':
          arr[i][0] = arr[i][0] + 48;
          break;
        case '—':
          arr[i][0] = arr[i][0] + 49;
          break;
        case 'ç':
          arr[i][0] = arr[i][0] + 50;
          break;
        case '':
          arr[i][0] = arr[i][0] + 51;
          break;
        case 'č':
          arr[i][0] = arr[i][0] + 52;
          break;
        case '™':
          arr[i][0] = arr[i][0] + 53;
          break;
        case 'é':
          arr[i][0] = arr[i][0] + 54;
          break;
        case 'ę':
          arr[i][0] = arr[i][0] + 55;
          break;
        case 'ë':
          arr[i][0] = arr[i][0] + 56;
          break;
        case 'ě':
          arr[i][0] = arr[i][0] + 57;
          break;
        case 'ť':
          arr[i][0] = arr[i][0] + 58;
          break;
        case 'í':
          arr[i][0] = arr[i][0] + 59;
          break;
        case 'ž':
          arr[i][0] = arr[i][0] + 60;
          break;
        case 'î':
          arr[i][0] = arr[i][0] + 61;
          break;
        case 'ź':
          arr[i][0] = arr[i][0] + 62;
          break;
        case 'ď':
          arr[i][0] = arr[i][0] + 63;
          break;
        }
      }

  cout<<"—â® ˘ë ĺ®â¨âĄ á¤Ą« âě:"<<endl;
  cout<<"1.•Ąč¨ŕ®˘ ­¨Ą Ż® ŻĄŕ˘®© ˇăŞ˘Ą  «ä ˘¨â :"<<endl;
  cout<<"2.•Ąč¨ŕ®˘ ­¨Ą Ż® ç¨á«ă Ł« áá­ëĺ ¨ ç¨á«ă á®Ł« á­ëĺ ˇăŞ˘ ˘ á«®˘ ĺ:"<<endl;
  cout<<"3.€˘â®ŕáŞ®Ą ĺĄč¨ŕ®˘ ­¨Ą:"<<endl;
  cout<<"4.‡ ˘Ąŕč¨âě Żŕ®Łŕ ¬¬ă:"<<endl;

  file.close();

  return 0;
}
