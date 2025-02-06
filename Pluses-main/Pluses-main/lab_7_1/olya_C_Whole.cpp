#include "olyaCWhole.h"
using namespace std;

int i;
Matrix::Matrix() {} //конструктор по умолчанию
Matrix::Matrix(int m[4], int key)  //конструктор с параметрами
{
    m_key=key;
    for(i=0;i<4;i++)
      m_M[i] = m[i];
}
Matrix::~Matrix() //деструктор
{
    cout<<"Матрица удалена"<<endl;
}
void Matrix::gm_M(int* arr)  //получение значений элементов матрицы из private
{
    for(i=0;i<4;i++)
      arr[i] = m_M[i];
}
int Matrix::gid() //получение идентификатора из private
{
  return m_key;
}
bool Matrix::chec(int id) //проверка идентификатора
{
    if (id == m_key)
      return true;
    else
      return false;
}




CWhole :: CWhole() //конструктор по умолчанию
{
  kol = 0;
}
CWhole ::~CWhole() //деструктор
{
  for (i = 0; i < kol; i++)
    delete m_p[i];
}
bool CWhole::add(int m[4], int key) //добавление элемента
{
    if (search(key) < 0)
    {
        m_p[kol] = new Matrix(m,key);
        kol++;
        cout<<"Новый элемент добавлен."<<endl;
        return true;
    }
    else
    {
      cout<<"Ошибка. Элемент с таким идентификатором уже существует."<<endl;
      return false;
    }
}
int CWhole::search(int id) //поиск по ключу
{
    for (i = 0; i < kol; i++)
      if (m_p[i]->chec(id))
        return i;
    return -1;
}
bool CWhole::del(int id)  //удаление по ключу
{
    int del = search(id);
    if (del < 0)
      return false;
    delete m_p[del];
    while (del < kol - 1)
    {
        m_p[del] = m_p[del + 1];
        del++;
    }
    kol--;
    return true;
}
// int CWhole::getn() // получение количества элементов
// {
//   return kol;
// }
void CWhole::output() //вывод всех векторов
{
    for (i=0; i < kol; i++)
    {
        cout << "Идентификатор: " <<m_p[i]->gid() << endl;
    }
}
void CWhole::outputid(int id) //вывод по ключу
{
    {
        for (i = 0; i < kol; i++)
            if (m_p[i]->chec(id))
                id = i;
        int *arr = new int[4];
        m_p[id]->gm_M(arr);
        cout <<  arr[0] << " ";
        cout <<  arr[1] << endl;
        cout <<  arr[2] << " ";
        cout  << arr[3] << endl;
        cout << endl;
    }
}
