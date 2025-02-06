#include <iostream> 

#include <math.h> 

#include "Triangle.h" 

 

using namespace std; 

void Triangle::defalt() { 

m_xcentr = (m_x1 + m_x2 + m_x3) / 3;//функция для поиска середины 

m_ycentr = (m_y1 + m_y2 + m_y3) / 3;//выполняется каждый проход цикла 

} 

Triangle::Triangle(int key) : m_x1(1), m_x2(2), m_x3(3), m_y1(1), m_y2(2), m_y3(3), m_key(key) 

{ 

m_xcentr = (m_x1 + m_x2 + m_x3) / 3;//конструктор по умолчанию 

m_ycentr = (m_y1 + m_y2 + m_y3) / 3; 

} 

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3, int key) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3), m_key(key) 

{										//параметризированный конструктор 

m_xcentr = (m_x1 + m_x2 + m_x3) / 3;// 

m_ycentr = (m_y1 + m_y2 + m_y3) / 3;// 

} 

void Triangle::print() {				//фунция вывода 

cout << m_x1 << ':' << m_y1 << endl;// 

cout << m_x2 << ':' << m_y2 << endl;// 

cout << m_x3 << ':' << m_y3 << endl;// 

}; 

void Triangle::set_x1(double x) { 

m_x1 = x; 

} 

void Triangle::set_x2(double x) { 

m_x2 = x; 

} 

void Triangle::set_x3(double x) { 

m_x3 = x; 

} 

void Triangle::set_y1(double x) { 

m_y1 = x; 

} 

void Triangle::set_y2(double x) { 

m_y2 = x; 

} 

void Triangle::set_y3(double x) { 

m_y3 = x; 

} 

double Triangle::get_x1() { 

return m_x1; 

} 

double Triangle::get_x2() { 

return m_x2; 

} 

double Triangle::get_x3() { 

return m_x3; 

} 

double Triangle::get_y1() { 

return m_y1; 

} 

double Triangle::get_y2() { 

return m_y2; 

} 

double Triangle::get_y3() { 

return m_y3; 

} 

void Triangle::rotate(double r) {//фунция поворота 

double x; 

m_x1 -= m_xcentr;//перемещение треугольника в начало координат 

m_x2 -= m_xcentr;// 

m_x3 -= m_xcentr;// 

m_y1 -= m_ycentr;// 

m_y2 -= m_ycentr;// 

m_y3 -= m_ycentr;// 

x = m_x1; 

m_x1 = x * cos((r / 180 * 3.14)) - m_y1 * sin((r / 180 * 3.14));//поворот всех его точек  

m_y1 = x * sin((r / 180 * 3.14)) + m_y1 * cos((r / 180 * 3.14));//с помощью специальных формул 

x = m_x2;														// 

m_x2 = x * cos((r / 180 * 3.14)) - m_y2 * sin((r / 180 * 3.14));// 

m_y2 = x * sin((r / 180 * 3.14)) + m_y2 * cos((r / 180 * 3.14));// 

x = m_x3;														// 

m_x3 = x * cos((r / 180 * 3.14)) - m_y3 * sin((r / 180 * 3.14));// 

m_y3 = x * sin((r / 180 * 3.14)) + m_y3 * cos((r / 180 * 3.14));// 

m_x1 += m_xcentr;// 

m_x2 += m_xcentr;// 

m_x3 += m_xcentr;//возврат повёрнутого треугольника в исходное положение 

m_y1 += m_ycentr;// 

m_y2 += m_ycentr;// 

m_y3 += m_ycentr;// 

return; 

} 

bool operator== (const Triangle& c1, const Triangle& c2) 

{									// 

return (c1.m_x1 == c2.m_x1 &&	// 

c1.m_x2 == c2.m_x2 &&		//перегрузка оператора сравнения 

c1.m_x3 == c2.m_x3 &&		// 

c1.m_y1 == c2.m_y1 &&		// 

c1.m_y2 == c2.m_y2 &&		// 

c1.m_y3 == c2.m_y3);		// 

} 

ostream& operator<<(ostream& os, const Triangle& triangle) { 

os << "points of triangle:" << endl;//перегрузка оператора вывода 

os << '(' << triangle.m_x1 << ',' << triangle.m_y1 << ')' << endl; 

os << '(' << triangle.m_x2 << ',' << triangle.m_y2 << ')' << endl; 

os << '(' << triangle.m_x3 << ',' << triangle.m_y3 << ')' << endl; 

return os; 

} 

bool Triangle::checkid(int id) 

{ 

if (id == m_key) return true; 

else return false; 

} 

void Triangle::setid(int id) { m_key = id; } 

// реализация метода проверки ключа 
