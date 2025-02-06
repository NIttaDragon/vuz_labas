#include <iostream>
class Matrix //объявление класса
{
public:
  int m_m=4;
  int m_M[4][4];
  Matrix(); //конструктор класса
  Matrix(int t[4][4]); //конструктор с параметром
  void show(); //вывод матрицы матрицы
  void NachMatr(); // начальная матрица
  void TraMat(); //транспонирование
  void YmnMat(int); //умножение
  void IzmTochZn(int,int,int); //изменение значений
  Matrix(const Matrix &obj); //копирование
  ~Matrix(); //деструктор
  //friend ostream& operator<<(ostream &stream, Matrix obj); //перегрузка оператора
};
