/* list.h -- ���� ��������� ���  ���� list */
#pragma warning(suppress : 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #include <Windows.h>
// #define TSIZE 45 /* ������ ������� ��� �������� ������ */
// #define  _CRT_SECURE_NO_WARNINGS
 enum Bool { false, true };

 struct student
{
	char name[TSIZE];
	int rating;
};
/* ����������� ����������� ���� */
 typedef enum Bool bool;
 typedef struct student Item;
typedef struct node
{
	Item item;
	struct node* next;
} Node;
typedef Node* List;
typedef  List T;
void InitializeList(List* );/* ������������� ������ ������ ��������� plist ������. �� ������*/
bool ListIsEmpty(const List plist); /* ������� ���������� �������� Tru�, ���� ������ ����*/
unsigned int ListItemCount(const List plist);/* ����������� ���������� ��������� � ������ */
bool AddItem(Item item, List* plist);/* ���������� �������� � ����� ������,item �  ����������� ������� */
void handlingListItems(const List plist, void (*pfun)(Item item));/* ���������� ������� � ������� �������� pfun ��������� �� ������� */
void EmptyTheList(List* plist);/*  ������������ ����������������� ������ */
void dataCollectionStorage(List *);
void CopyToNode(Item item, Node* pnode);/* �������� ��������� ������� */
void AddFirst(List* plist);// ���������� �������� � ������ ������
void AddMiddl(List plist);
Item CreateNewStudent(void);
List CreateNode(Item item);// ��������� �� ����� ����
void AddAfter(List* plist, List newNode, unsigned k);
void FindRating(List Head, char findVal[]);
void DeleteNode(List* pHead, List delNode);
List FindForDel(List Head, char findVal[]);
void showstudents(Item item);
List* CreatIndex(List Head);
void sbl(T* v, int n);
void bl(T* v, int n);
void swap(void* a, void* b);
