#include <iostream>
using namespace std;

// сортировка слиянием

void merge(int *arr, int first, int last, int mid)
{
  int i = first;
  int k = first;
  int j = mid + 1;
  int *mas=new int [last+1];
  while (i <= mid && j <= last)
  {
    if (arr[i] < arr[j])
    {
      mas[k] = arr[i];
      k++;
      i++;
    }
    else
    {
      mas[k] = arr[j];
      k++;
      j++;
    }
  }
  while (i <= mid)
  {
    mas[k] = arr[i];
    k++;
    i++;
  }
  while (j <= last)
  {
    mas[k] = arr[j];
    k++;
    j++;
  }
  for (i = first; i < k; i++)
    arr[i] = mas[i];
  delete []mas;
}

void merge_sort(int *arr, int first, int last)
{
  int mid;
  if (first < last)
  {
    mid = (first + last)/2;
    merge_sort(arr, first, mid);
    merge_sort(arr, mid+1, last);
    merge(arr, first, last, mid);
  }
}

int main()
{
  int arr[100000], i;
  int m=100000;
  for (i=0;i<m;i++) //рандомное заполнение массива
      arr[i]=rand()%1000;

  for(i=0; i<m; i++)
    cout<<arr[i]<<" ";
  merge_sort(arr,0,m-1);
  cout<<endl;
  for(i=0; i<m; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}
