#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
  int n = 700, i = 0;
  string array[n];
  int arr[n];
  ifstream file;  //создание потока для чтения файла
  file.open("text.txt"); //открытие файла для чтения

  while (!file.eof()) //чтение из файла в массив и вывод на экран
  {
    file >> array[i];
    cout << array[i] << "; ";
    i++;
  }
  cout << endl;

  cout<<array[1][3]<<endl;

  file.close(); //закрытие файла
  return 0;
}
