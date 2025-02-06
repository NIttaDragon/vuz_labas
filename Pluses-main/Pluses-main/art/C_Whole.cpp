#include "CWhole.h" 

 

CWhole :: CWhole() { m_count = 0; } 

CWhole ::~CWhole() { for (int i = 0; i < m_count; i++) delete m_a[i]; } 

 

bool CWhole::add(double x1, double x2, double x3, double y1, double y2, double y3, int key) { 

if (search(key) < 0) { // ищем в массиве – есть ли уже объект с таким ключем 

m_a[m_count] = new Triangle(x1,x2,x3,y1,y2,y3,key); //добавляем, если нет 

m_count++; 

return true; //и возвращаем true 

} 

return false; // если уже есть – возвращаем false 

} 

 

int CWhole::search(int id) { 

for (int i = 0; i < m_count; i++) if (m_a[i]->checkid(id)) return i; 

return -1; 

} 

 

bool CWhole::del(int id) { 

int del = search(id); //находим номер объекта с таким ключом 

if (del < 0) return false; // если его нет – возвращаем false 

delete m_a[del]; // удаляем объект по найденному выше номеру 

while (del < m_count - 1) 

{ // сдвигаем объекты в массиве, которые следуют за удаленным 

m_a[del] = m_a[del + 1]; 

del++; 

} 

m_count--; // уменьшаем кол-во объектов в массиве на единицу 

return true; 

} 

void CWhole::output() {//вывод всех треугольников 

for (int i=0; i < m_count; i++) { 

std::cout << "id: " <<m_a[i]->getid() << std::endl; 

std::cout << "coords: " << std::endl; 

m_a[i]->print(); 

std::cout << std::endl; 

} 

} 
