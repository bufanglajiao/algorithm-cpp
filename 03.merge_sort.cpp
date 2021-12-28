#include <iostream>
#include "SortTestHelper.h"

using namespace std;

/**
 * 将arr[left...middle]和[middle+1...right]进行归并
 * @tparam T
 * @param arr
 * @param left
 * @param middle
 * @param right
 */
template<typename T>
void __merge(T arr[], int left, int middle,int right) {
  T *aux = new T[right-left+1];
  for (int i = left; i <= right; ++i) {
    aux[i-left] = arr[i];
  }
  // 初始化，i指向左半部分的起始索引位置l；j指向右半部分起始索引位置mid+1
  int i = left, j = middle+1;
  for (int k = left; k <= right; ++k) {// k指向临时数组
    if( i > middle ){  // 如果左半部分元素已经全部处理完毕
      arr[k] = aux[j-left];
      j++;
    }
    else if( j > right ){  // 如果右半部分元素已经全部处理完毕
      arr[k] = aux[i-left];
      i++;
    }
    else if( aux[i-left] < aux[j-left] ) {  // 左半部分所指元素 < 右半部分所指元素
      arr[k] = aux[i-left];
      i++;
    }
    else{  // 左半部分所指元素 >= 右半部分所指元素
      arr[k] = aux[j-left];
      j++;
    }
  }

  delete[] aux;
}
/**
 * 递归使用归并排序，对arr[left...right]范围进行排序
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */
template<typename T>
void __mergeSort(T arr[], int left, int right) {
  if(left >= right) return; // 最优解应该是遇到小范围的时候就转用插入排序
  int middle = (left + right) / 2;
  __mergeSort(arr, left, middle);
  __mergeSort(arr, middle+1, right);
  if(arr[middle] > arr[middle+1]){
    __merge(arr, left, middle, right);
  }
}

template<typename T>
void mergeSort(T arr[], int n) {
  __mergeSort(arr, 0, n-1);
}

/**
 * 归并排序法（自顶向下）——nlogn
 * @return
 */
int main() {
  int n = 50000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::generateNearlyOrderedArray(n, 100);
  SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
  SortTestHelper::testSort("Merge Sort(NearlyOrderedArray)", mergeSort, arr2, n);
  delete[] arr;
  delete[] arr2;
  return 0;
}

