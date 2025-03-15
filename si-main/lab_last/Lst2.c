// Lst2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define   Len 40
typedef struct node {
	char word[Len]; // область данных
	int count;
	struct node* next, * prev; // ссылки на соседние узлы
}Node;
typedef Node* pNode; // тип данных «указатель на узел»

pNode CreateNode();
pNode CreateNodeFam(char* NewWord);
void AddFirst(pNode* Head, pNode* Tail, pNode NewNode);
void AddLast(pNode* Head, pNode* Tail, pNode NewNode);
pNode Find(pNode Head, char NewWord[]);
void AddAfter(pNode* Head, pNode* Tail, pNode p, pNode NewNode);
void Delete(pNode* Head, pNode* Tail, pNode OldNode);
void prn(pNode);
void Prn(pNode pnode);
int i = 0;

int main()
{
pNode Head = NULL, Tail = NULL;// для пустого списка
pNode NewNode = CreateNode();
AddFirst(&Head, &Tail,NewNode);
prn(Head);
AddFirst(&Head, &Tail, CreateNode());
prn(Head);
AddLast(&Head, &Tail, CreateNode());
prn(Head);
printf("Fam for find-?");char FindWord[Len];scanf("%s", FindWord, Len);
pNode x=Find(Head, FindWord);
printf("%-10s\t%d\n", x->word, x->count);
printf("Fam for insert-?"); char InsWord[Len]; scanf("%s", InsWord, Len);
pNode InsNode = CreateNodeFam(InsWord);
AddAfter(&Head, &Tail, x, InsNode);
prn(Head);
printf("Fam for delete-?"); char DelWord[Len]; scanf("%s", DelWord, Len);
pNode DelNode = Find(Head, DelWord);
Delete(&Head, &Tail,DelNode);
prn(Head);
Prn(Head);
}

pNode CreateNode()
{
	pNode NewNode = (pNode)malloc(sizeof(Node)); // указ. на новый узел
	printf("Fam-?");
	char NewWord[Len];
	scanf("%s", NewWord,Len);
	strcpy(NewNode->word,Len, NewWord); // записать слово
	NewNode->count = ++i; // счетчик
	NewNode->next = NULL; // следующего узла нет
	return NewNode; // результат функции – адрес узла
}
pNode CreateNodeFam(char *NewWord)
{
	pNode NewNode = (pNode)malloc(sizeof(Node)); // указ. на новый узел

	strcpy(NewNode->word, Len, NewWord); // записать слово
	NewNode->count = ++i; // счетчик
	NewNode->next = NULL; // следующего узла нет
	return NewNode; // результат функции – адрес узла
}
//Добавление узла в начало списка
void AddFirst(pNode* Head, pNode* Tail, pNode NewNode)
{
	NewNode->next = *Head;
	NewNode->prev = NULL;
	if (*Head) (*Head)->prev = NewNode;
	*Head = NewNode;
	if (!*Tail) *Tail = *Head; // этот элемент – первый
}
//Добавление узла в конец списка
void AddLast(pNode* Head, pNode* Tail, pNode NewNode)
{
	NewNode->prev = *Tail;
	NewNode->next = NULL;
	if (*Tail) (*Tail)->next = NewNode;
	*Tail = NewNode;
	if (!*Head) *Head = *Head; // этот элемент – первый
}

pNode Find(pNode Head, char NewWord[])
{
	pNode q = Head;
	while (q && strcmp(q->word, NewWord))
		q = q->next;
	return q;
}
//Удаление узла
void Delete(pNode* Head, pNode* Tail, pNode OldNode)
{
	if (*Head == OldNode) {
		*Head = OldNode->next; // удаляем первый элемент
		if (*Head) (*Head)->prev = NULL;
		else *Tail = NULL; // удалили единственный элемент
	}
	else {
		OldNode->prev->next = OldNode->next;
		if (OldNode->next)
			OldNode->next->prev = OldNode->prev;
		else *Tail = NULL; // удалили последний элемент
	}
	free(OldNode);
}

void AddAfter(pNode* Head, pNode* Tail,	pNode p, pNode NewNode)
{
	if (!p->next)
		AddLast(Head, Tail, NewNode); // вставка в конец списка
	else {
		NewNode->next = p->next; // меняем ссылки нового узла
		NewNode->prev = p;
		p->next->prev = NewNode; // меняем ссылки соседних узлов
		p->next = NewNode;
	}
}

//Вывод списка
void prn(pNode pnode)
{
	while (pnode)
	{
		printf("%-10s\t%d\n", pnode->word, pnode->count);
		pnode = pnode->next;
	}
}

void Prn(pNode pnode)
{
	printf("\n");
	printf("%p\n", &pnode);
	printf("%p\n", pnode);
	while (pnode)
	{
		printf("%p  %p       %-10s  %d   %p\n",pnode,pnode->prev, pnode->word, pnode->count,pnode->next);
		pnode = pnode->next;
	}
}
