#include <stdio.h>
#include <malloc.h>
#define k 5

//сортировка вставками
int InSort(int m[],int kol)
{
    int nel, loc;
    for (int i = 1; i < k; i++)
    {
        nel = m[i];
        loc = i - 1;
        while((loc>=0)&&(m[loc]>nel))
        {
            m[loc+1] = m[loc];
            loc = loc - 1;
            kol++;
        }
        m[loc+1] = nel;
    }
    return kol;
}

int main()
{
    int m[k]={4,3,7,9,1};
    int kol=0; int srav;
    int* p;
    printf("Начальный массив:\n");
    for (int i = 0; i < k; i++)
    {
      printf("%d ", m[i]);
      //p=&m[i];
    }
    printf("\n");
    //сортировка вставками
    srav=InSort(m,kol);
    //вывод отсортированного массива на экран
    printf("Отсортированный массив:\n");
    for (int i = 0; i < k; i++)
        printf("%d ", m[i]);
    printf("\n");
    printf("Количество сравнений и перестановок после сортировки вставками %i\n",srav);

    return 0;
}
