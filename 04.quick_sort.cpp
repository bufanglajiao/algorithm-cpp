#include <iostream>
#include "SortTestHelper.h"

using namespace std;

/**
 * 对arr[left...right]进行partition操作
 * 返回p,使得arr[left...p-1]<arr[p]; arr[p+1...right]>arr[p];
 * 对于带有很多重复值的小范围的排序，会导致本方法的2部分数组不平衡，可以考虑双路快排、三路快排
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */
template<typename T>
int __partition(T arr[], int left, int right) {
  // 随机选择一个元素作为partition,避免树退化为n^2
  swap(arr[left], arr[rand()%(right-left+1)+left]);
  T v = arr[left]; // 默认选择第一个元素作为partition
  // arr[left+1...j]< v; arr[j+1...i] > v;
  int j = left;
  for (int i = left + 1; i <= right; ++i) {
    if(arr[i] < v) {
      swap(arr[++j], arr[i]);
    }
  }
  swap(arr[left], arr[j]);
  return j;
}

/**
 * 对arr[left...right]部分进行快速排序
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */
template<typename T>
void __quickSort(T arr[], int left, int right) {
  if(left >= right) return;
  int p = __partition(arr, left, right);
  __quickSort(arr, left, p-1);
  __quickSort(arr, p+1, right);
}

template<typename T>
void quickSort(T arr[], int n) {
  srand(time(NULL));
  __quickSort(arr, 0, n-1);
}

/**
 * 快速排序——nlogn
 * @return
 */
int main() {
  int n = 50000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::generateNearlyOrderedArray(n, 100);
  SortTestHelper::testSort("Quick Sort", quickSort, arr, n);
  SortTestHelper::testSort("Quick Sort(NearlyOrderedArray)", quickSort, arr2, n);
  delete[] arr;
  delete[] arr2;
  return 0;
}

