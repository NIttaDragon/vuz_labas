#include "spec7.h"
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
int Matrix::chec(int id) //проверка идентификатора
{
    if (id == m_key)
      return 1;
    else
      return -1;
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
void CWhole::add(int m[4], int key) //добавление элемента
{
    if (search(key) < 0)
    {
        m_p[kol] = new Matrix(m,key);
        kol++;
        cout<<"Новый элемент добавлен."<<endl;
    }
    else
      cout<<"Ошибка. Элемент с таким идентификатором уже существует."<<endl;
}
int CWhole::search(int id) //поиск по ключу
{
    for (i = 0; i < kol; i++)
      if ((m_p[i]->chec(id))==1)
        return i;
    return -1;
}
void CWhole::del(int id)  //удаление по ключу
{
    int d = search(id);
    if (d >= 0)
    {
      delete m_p[d];
      while (d < kol - 1)
      {
          m_p[d] = m_p[d + 1];
          d++;
      }
      kol--;
    }
}
int CWhole::getn() // получение количества элементов
{
  return kol;
}
void CWhole::output() //вывод идентификаторов матриц
{
    for (i=0; i < kol; i++)
    {
        cout << "Идентификатор: " <<m_p[i]->gid() << endl;
    }
    if(kol==0)
      cout<<"Нет созданных матриц"<<endl;
}
void CWhole::outputid(int id) //вывод по ключу
{
    {
        for (i = 0; i < kol; i++)
            if ((m_p[i]->chec(id))==1)
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
