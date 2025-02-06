#include <iostream> 

#include "Triangle.h" 

 

class CWhole 

{ 

private: 

 int m_count; 

public: 

    Triangle* m_a[20]; // массив указателей на объект-часть  

    CWhole(); 

    ~CWhole(); 

    int getn() { return m_count; } // получение кол-ва элементов 

    bool del(int id); // удаление объекта по ключу 

    bool add(double x1, double x2, double x3, double y1, double y2, double y3, int key); //добавление объекта 

    int search(int id); // поиск объекта по ключу 

    void output(); 

}; 
