#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stud
{
  struct Stud *next;
  struct student *prev;
  char im[25];
  char fam[25];
  char god[5];
  char score[5];
} t_ls;
void show(t_ls c);

t_ls *create_node(char *im, char *fam, char *god, char *score) /*Создание элемента*/
{
  t_ls *node = (t_ls *)malloc(sizeof(t_ls));
  strcpy(node -> im, m);
  strcpy(node -> fam,fam);
  strcpy(node -> god, god);
  strcpy(node -> score,score);
  node -> next = NULL;
  return node;
}

int main()
{
  FILE *list = fopen("list.txt", "r");
  FILE *lost = fopen ("lost.txt", "w");
  char napr[100];
  char im, fam, god, score;
  t_ls x;
  struct Stud *p = &x;

  printf("Выберите оценку по которой будет произведен отбор:\n");
  printf("1. 5\n");
  printf("2. 4\n");
  printf("3. 3\n");
  printf("4. 2\n");
  scanf("%s",napr);
  printf("Результаты скопированы в lost.txt\n", napr);
  t_ls *list = create_node("TEST", "TEST", 0, 0);
  while (!feof(Stud))
  {
    fscanf(Stud, "%s %s %s %s", im, fam, god, score);
    if (!strcmp(napr, p->score))
    {
      printf("%s %s %s %s\n", list -> im, list -> fam, list -> god, list -> score);
      fprintf(lost, "%s %s %s %s\n", list -> im, list -> fam, list -> god, list -> score);
    }
  }
  fclose(list);
  fclose(lost);
  return 0;
}
