#include <iostream>
#include <SortTestHelper.h>
using namespace std;

/**
 * 选择排序
 * @param arr 待排序数组
 * @param n 数组的长度
 */
template<typename T>
void selectionSort(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    // 寻找[i, n)区间里的最小值
    int minIndex = i;
    for (int j = i + 1; j < n; ++j) {
      if(arr[j] < arr[minIndex]){
        minIndex = j;
      }
    }
    swap(arr[i], arr[minIndex]);
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
  SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
  delete[] arr;
  return 0;
}
