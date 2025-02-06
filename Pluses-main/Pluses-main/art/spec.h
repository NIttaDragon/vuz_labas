#include <iostream>
using namespace std;

class Triangle
{
//private://задание приватных полей
  int m_key;
  double m_x1;
  double m_x2;
  double m_x3;
  double m_y1;
  double m_y2;
  double m_y3;
  double m_xcentr, m_ycentr;
public://прототипы функций
  Triangle(int m_key);
  Triangle(double x1, double x2, double x3, double y1, double y2, double y3, int m_key);
  ~Triangle() = default;
  void print();
  void set_x1(double x);
  void set_x2(double x);
  void set_x3(double x);
  void set_y1(double x);
  void set_y2(double x);
  void set_y3(double x);
  double get_x1();
  double get_x2();
  double get_x3();
  double get_y1();
  double get_y2();
  double get_y3();
  void defalt();
  void rotate(double r);
  int getid() { return m_key; } // получить значение ключа
  void setid(int key); // изменить значение ключа
  bool checkid(int key); // метод проверки ключа
  friend bool operator== (const Triangle& c1, const Triangle& c2);
  friend  ostream& operator <<( ostream& os, const Triangle& triangle);
};


class CWhole
{
//private:
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
