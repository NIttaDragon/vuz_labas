#include <iostream> 

#include "CWhole.h" 

#include <conio.h> 

int main() { 

CWhole arrtr; 

double x1,x2,x3,y1,y2,y3; 

int key; 

while (true) { 

std::cout << "Choose an action:" << std::endl;	// 

std::cout << "1-print triangles" << std::endl;	// 

std::cout << "2-add triangle" << std::endl;     // 

std::cout << "3-delete triangle" << std::endl;	//вывод меню 

std::cout << "4-exit" << std::endl;				// 

switch (_getch()) {		//выбор нужного элемента меню 

case '1'://элемент, который выводит все треугольники 

arrtr.output(); 

system("pause"); 

system("cls"); 

break; 

case'2'://элемент, который добавляет треугольник 

std::cout << "x1:"; 

std::cin >> x1; 

std::cout << "x2:"; 

std::cin >> x2; 

std::cout << "x3:"; 

std::cin >> x3; 

std::cout << "y1:"; 

std::cin >> y1; 

std::cout << "y2:"; 

std::cin >> y2; 

std::cout << "y3:"; 

std::cin >> y3; 

std::cout << "key:"; 

std::cin >> key; 

arrtr.add(x1, x2, x3, y1, y2, y3,key); 

system("cls"); 

break; 

case'3'://элемент, который удаляет треугольник 

std::cout << "key:"; 

std::cin >> key; 

arrtr.del(key); 

system("cls"); 

break; 

case'4'://выход из программы 

return 0; 

break; 

} 

} 

} 
