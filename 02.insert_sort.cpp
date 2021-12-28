#include <iostream>
#include <Student.h>
#include <SortTestHelper.h>
using namespace std;


/**
 * 插入排序
 * @param arr 待排序数组
 * @param n 数组的长度
 */
template<typename T>
void insertionSort2(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    // 寻找元素arr[i]合适的插入位置
    for (int j = i; j > 0 && arr[j] < arr[j-1]; --j) {
      swap(arr[j], arr[j-1]);
    }
  }
}
/**
 * 插入排序（优化）一次赋值
 * @param arr 待排序数组
 * @param n 数组的长度
 */
template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    // 寻找元素arr[i]合适的插入位置
    T e = arr[i];
    int j; // 保存元素e应该插入的位置
    for (j = i; j > 0 && arr[j - 1] > e; --j) {
      arr[j] = arr[j-1];
    }
    arr[j] = e;
  }
}

/**
 * O（n^2）的排序算法
 * 该算法是排序算法的基础，编码简单，易于实现，是一些简单情景的首选。
 * 在一些特殊的情况下，简单的排序算法更有效。
 * 简单的排序算法思想衍生出复杂的排序算法。
 * 作为子过程，改进更复杂的排序算法。
 * @return
 */
int main() {
  int n = 10000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  int *arr2 = SortTestHelper::generateNearlyOrderedArray(n, 100);
  SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
  SortTestHelper::testSort("Insertion Sort(NearlyOrderedArray)", insertionSort, arr2, n);
  delete[] arr;
  delete[] arr2;
  return 0;
}
