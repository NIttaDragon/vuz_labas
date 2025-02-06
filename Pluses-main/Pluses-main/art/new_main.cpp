#include <iostream>
#include "CWhole.cpp"
//#include <conio.h>
using namespace std;

int main()
{
  CWhole C;
  CWhole *C2=new CWhole;
  double x1,x2,x3,y1,y2,y3;
  int key;
  int a;
  while (true) {
    cout << "Choose an action:" <<  endl;	//
    cout << "1-print triangles" <<  endl;	//
    cout << "2-add triangle" <<  endl;     //
    cout << "3-delete triangle" <<  endl;	//вывод меню
    cout << "4-exit" <<  endl;				//
    cin>>a;
    switch (a)
    {		//выбор нужного элемента меню
      case 1://элемент, который выводит все треугольники
        C2->output();
          //system("pause");
          //system("cls");
          break;
      case 2://элемент, который добавляет треугольник
        cout << "x1:";
        cin >> x1;
        cout << "x2:";
        cin >> x2;
        cout << "x3:";
        cin >> x3;
        cout << "y1:";
        cin >> y1;
        cout << "y2:";
        cin >> y2;
        cout << "y3:";
        cin >> y3;
        cout << "key:";
        cin >> key;
        C2->add(x1, x2, x3, y1, y2, y3,key);
        //system("cls");
        break;
      case 3://элемент, который удаляет треугольник
        cout << "key:";
        cin >> key;
        C2->del(key);
        //system("cls");
        break;
      case 4://выход из программы
        return 0;
        break;
      }
    }
}
