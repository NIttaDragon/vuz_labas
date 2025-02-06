#include <iostream>

class Matrix
{
    int m_M[4];	//элементы матрицы
    int m_key; //идентификатор матрицы
public:
    Matrix();	//конструктор по умолчанию
    Matrix(int m[4], int key);	//конструктор с параметрами
    ~Matrix(); //деструктор
    void gm_M(int* arr);	//получение значений элементов матрицы из private
    bool chec(int key); //проверка идентификатора
    int gid(); //получение идентификатора из private
};


class CWhole
{
    int kol;
public:
    Matrix* m_p[20]; // массив указателей на объект-часть
    CWhole(); //конструктор по умолчанию
    ~CWhole(); //деструктор
    // int getn(); // получение количества элементов
    bool del(int id); // удаление объекта по ключу
    bool add(int m[4], int key); //добавление объекта
    int search(int id); // поиск по ключу
    void output(); //вывод всех векторов
    void outputid(int id); //вывод по ключу
};
