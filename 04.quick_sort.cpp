#include <iostream>
#include "SortTestHelper.h"

using namespace std;

/**
 * ��arr[left...right]����partition����
 * ����p,ʹ��arr[left...p-1]<arr[p]; arr[p+1...right]>arr[p];
 * ���ڴ��кܶ��ظ�ֵ��С��Χ�����򣬻ᵼ�±�������2�������鲻ƽ�⣬���Կ���˫·���š���·����
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */
template<typename T>
int __partition(T arr[], int left, int right) {
  // ���ѡ��һ��Ԫ����Ϊpartition,�������˻�Ϊn^2
  swap(arr[left], arr[rand()%(right-left+1)+left]);
  T v = arr[left]; // Ĭ��ѡ���һ��Ԫ����Ϊpartition
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
 * ��arr[left...right]���ֽ��п�������
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
 * �������򡪡�nlogn
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

