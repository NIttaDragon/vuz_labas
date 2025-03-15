#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

int main(void)
{

  struct Node* some =create(0);
  printf("%d\n",some->data);
  int k=0;
  while(k!=1)
  {
    printf("Что вы хотите сделать?\n");
    // printf("1.Добавить узел в начало списка");
    printf("2.Добавить несколько элементов в конец списка\n");
    // printf("3.Добавить узел в определенное место списка");
    // printf("4.Удалить определенный узел списка");
    // printf("5.Вывести список на экран");
    // printf("6.Найти элемент по индексу\n");
    printf("7.Завершить программу\n");
    int a,n;
    scanf("%d\n", &a);
    switch(a)
    {
      // case 1:
      //   addFirst();
      //   break;
      case 2:
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
          addLast(some,i);
          printf("elem: %d\n",findelem(some,i)->data);
        }
        break;
      // case 3:
      //   addN();
      //   break;
      // case 4:
      //   remN();
      //   break;
      // case 5:
      //   while(tmp!=NULL)
      //   {
      //     printf("%d",tmp->value);
      //     tmp=tmp->next;
      //   }
      //   break;
      // case 6:
      //   for(int i;i<n;i++)
      //
      //   break;
      case 7:
        k=1;
        break;
    }
  }
  return 0;
}
