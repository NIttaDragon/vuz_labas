# include <iostream>
using namespace std;

// пирамидальная сортировка

void heapify(int *arr, int m, int i)
{
  int larg = i;
  int l = 2*i + 1;
  int r = 2*i + 2;
  if(l < m && arr[l] > arr[larg])
    larg =l;
  if(r < m && arr[r] > arr[larg])
    larg = r;
  if(larg != i)
  {
    swap(arr[i], arr[larg]);
    heapify(arr, m, larg);
  }
}

void heap_sort(int *arr, int m)
{
  for (int i = m / 2 - 1; i >= 0; i--)
    heapify(arr, m, i);
  for (int i = m - 1; i >= 0; i--)
  {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

int main()
{
  int arr[10];
  int i;
  int m=10;
  for (i=0;i<m;i++) //рандомное заполнение массива
    {
      arr[i]=rand()%10;
    }
  for(i=0;i<m;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
  heap_sort(arr,m);

  for(i=0;i<m;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}
