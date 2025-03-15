// List1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// #define  _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
#include "list.h" /* определение типов List, Item */
//#include <locale.h>
// #include <Windows.h>
void showstudents(Item item);
int main(void)
{
	List students;
	List* Ind = NULL;
	InitializeList(&students);/* инициализация */
	dataCollectionStorage(&students);/* сбор и сохранение информации */
	printf("Список студентов:\n");
	handlingListItems(students, showstudents);/* вывод списка */
	printf("Вы ввели %d студентов.\n", ListItemCount(students));
	AddFirst(&students);// добавление элемента в начало списка
	printf("Список студентов:\n");
	handlingListItems(students, showstudents);/* вывод списка */
	printf("Вы ввели %d студентов.\n", ListItemCount(students));
	AddMiddl(students);
	printf("Список всех студентов:\n");
	handlingListItems(students, showstudents);
	printf("Найти студента ? :\n");
	char name[TSIZE];
	scanf("%s",name, TSIZE);
	FindRating(students, name);
	printf("Найти студента для удаления :\n");
	scanf("%s", name, TSIZE);
	DeleteNode(&students, FindForDel(students, name));
	printf("Актуальный список всех студентов:\n");
	handlingListItems(students, showstudents);
	Ind = CreatIndex(students);
	int n = ListItemCount(students);
	printf("\n");
	printf("________________\n");
	for (int i = 0; i < n; i++)
		printf("\n Имя %s  рейтинг %d ", (*(Ind + i))->item.name, (*(Ind + i))->item.rating);
	printf("\n");
	// printf("________________\n");
	// sbl(Ind, n);
	// for (int i = 0; i < n; i++)
	// 	printf("\n Имя %s  рейтинг %d ", (*(Ind + i))->item.name, (*(Ind + i))->item.rating);
	// printf("\n");
	// printf("________________\n");
	EmptyTheList(&students);/* очистка памяти */
	free(Ind);
	printf("Программа завершена.\n");
	return 0;
}
