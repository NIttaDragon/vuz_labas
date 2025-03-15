#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <conio.h>

struct Node
{
    char data[30];
    Node *next;
};

int main()
{
  Node *start;
  char str[30];
  Node *spis=new Node;
  strcpy(spis->data,"0");
  spis->next=NULL;
  start=spis;
  for(int i=1;i<10;i++)
  {
    spis->next=new Node;
    printf("element: ");
    fgets(str);
    strcpy(spis->next->data,str);
    spis->next->next=NULL;
    spis=spis->next;
  }
  printf("\n\n");
  spis=start;
  while(spis)
  {
    printf("%s\n",spis->data);
    spis=spis->next;
  }

  Node *tmp;
  spis=start;
  while(spis)
  {
    tmp=spis;
    spis=spis->next;
    delete tmp;
  }
  getc();
  return 0;
}
