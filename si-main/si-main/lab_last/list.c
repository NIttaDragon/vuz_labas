/* list.c -- �������, �������������� �������� �� ������� */

#include "list.h"

/* ������� ���������� */
void InitializeList(List* plist)/* ������������  ������ */
{
	*plist = NULL;
}

bool ListIsEmpty(const List plist)/* ��������� ���������  ������� */
{
	if (plist == NULL)
		return true;
	else
		return false;
}

unsigned int ListItemCount(const List plist)/* ������������  ���������� ����� */
{
	unsigned int count = 0;
	Node* pnode = plist; /* ��������� �� ������ ������ */
	while (pnode != NULL)
	{
		++count;
		pnode = pnode->next; /* ��������� �� ��������� ���� */
	}
	return count;
}

bool AddItem(Item item, List * plist) /* ������� ���� ��� �������� �������� � ��������� ��� � ����� ������ */
{
	Node* pnew;
	Node* scan = *plist;
	pnew = (Node*)malloc(sizeof(Node));
	if (pnew == NULL)
		return false; /* ����� �� ������� � ������ ������ */
	CopyToNode(item, pnew);
	pnew->next = NULL;
	if (scan == NULL) /* ������ ����, ������� �������� */
		*plist = pnew; /* pnew � ������ ������ */
	else
	{
		while (scan->next != NULL)
			scan = scan->next; /* ���� ����� ������ */
		scan->next = pnew; /* ��������� pnew � ����� */
	}
	return true;
}

void handlingListItems(const List plist, void (*pfun)(Item item))/* �  ������  ����� ��������� �������, pfun */
{
	if (ListIsEmpty(plist))
		printf("������ �� ���� �������. ");
	else
	{
		Node* pnode = plist; /* ������������� ��������� �� ������ ������ */
		while (pnode != NULL)
		{
			(*pfun)(pnode->item); /* ��������� ������� � �������� */
			pnode = pnode->next; /* ������� � ���������� �������� */
		}
	}
}

void EmptyTheList(List* plist)/* ����������� ������ */
{
	Node* psave;
	while (*plist != NULL)
	{
		psave = (*plist)->next; /* ���������� ������ ���������� ���� */
		free(*plist); /* ������������ �������� ���� */
		*plist = psave; /* ������� � ���������� ����, ��������� ��� ������������� ��������� ������ � NULL  */
	}
}
/* �������� ������� � ���� */
 void CopyToNode(Item item, Node* pnode)
{
	pnode->item = item; /* ����������� ��������� */
}

 List CreateNode(Item item)// ��������� �� ����� ����
 {
	 List pnew;
	 pnew = (Node*)malloc(sizeof(Node));
	 if (pnew == NULL)
		 return false; /* ����� �� ������� � ������ ������ */
	 CopyToNode(item, pnew);
	 pnew->next = NULL;// ���������� ���� ���� ���
	 return pnew; //  ����� ����
 }
 void AddAfter(List *plist, List newNode, unsigned k)
 {
	 //printf("\n   ���2=  %s   %d   %p\n", (*newNode).item.name, newNode->item.rating, newNode->next);
	 List pnode = *plist; /* ������������� ��������� �� ������ ������ */
	// printf("\n   ���2=  %s   %d   %p\n", (**plist).item.name, (** plist).item.rating, (**plist).next);
	 for (int i = 1; i != k; i++)
	 {
		 printf("%s   %d   %p", pnode->item.name,pnode->item.rating,pnode->next);
		 pnode = pnode->next; /* ������� � ���������� �������� */
	 }
	 newNode->next = pnode->next;
	 pnode->next = newNode;
 }

 
