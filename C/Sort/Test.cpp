#include <iostream>
#include <algorithm>
#include"Sort.h"
using namespace std;
#define SIZE 11

  template<typename T> //整数或浮点数皆可使用,若要使用类(class)或结构体(struct)时必须重载大于(>)运算符
  void bubble_sort(T arr[], int len) {
      int i, j;
      for (i = 0; i < len - 1; i++)
          for (j = 0; j < len - 1 - i; j++)
              if (arr[j] > arr[j + 1])
                  swap(arr[j], arr[j + 1]);
  }
 int main() {
     int arr[] = { 61, 22, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
     //int arr[] = {2,4,6,8,10,1,3,5,7,9,11};
     int len = (int)sizeof(arr) / sizeof(*arr);
     //Merge(arr,0,4,5,10);
     //bubble_sort(arr, len);
     //BubbleSort(arr, len);
     //SelectSort(arr,len);
     //InsertSort(arr,len);
     //ShellSort(arr,len);
     //MergeSort(arr,len);
     //MergeSortR(arr, 0, len-1);
     //QuickSort(arr,0,len -1);
     HeapSort(arr, len);
     //BucketSort(arr, len);
     //CountSort(arr, len);
     //RadixSort(arr, len);

     for (int i = 0; i < len; i++)
          cout << arr[i] << ' ';
     cout << endl;
     float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
     len = (float)sizeof(arrf) / sizeof(*arrf);
     bubble_sort(arrf, len);
     for (int i = 0; i < len; i++)
         cout << arrf[i] << ' ' << endl;
     return 0;
}