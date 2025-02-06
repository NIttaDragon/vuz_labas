#include <iostream>
#include "olyaCWhole.cpp"
using namespace std;

int main()
{
    CWhole W; //объявление объекта класса
    CWhole *W2=new CWhole; //массив указателей
    int m1,m2,m3,m4,key,b,k;
    while (k!=0)
    {
        cout<<endl;
        cout << "Выберите действие:" << endl;
        cout << "1. Вывести матрицу по ключу " << endl;
        cout << "2. Вывести все идентификаторы элементов" << endl;
        cout << "3. Добавить новую матрицу " << endl;
        cout << "4. Удалить матрицу по ключу" << endl;
        cout << "5. Выйти из программы" << endl;
        int* arr = new int[4]{m1,m2,m3,m4};
        cin>>b; cout<<endl;
        switch (b)
        {
            case 1:        //вывод матрицы по ключу
                cout << "Введите ключ:";
                cin >> key;
                W2->outputid(key);
                break;
            case 2:       //вывод всех идентификаторов
                W2->output();
                break;
            case 3:      //добавление матрицы
                cout << "M[1][1]:"; cin >> m1;
                cout << "M[1][2]:"; cin >> m2;
                cout << "M[2][1]:"; cin >> m3;
                cout << "M[2][2]:"; cin >> m4;
                cout << "Идентификатор:";
                cin >> key;
                arr[0]=m1;
                arr[1]=m2;
                arr[2]=m3;
                arr[3]=m4;
                W2->add(arr ,key);
                break;
            case 4:    //удаление матрицы
                cout << "Введите ключ:";
                cin >> key;
                W2->del(key);
                break;
            case 5:    //выход из программы
                k=0;
                break;
        }
    }
    return 0;
}
