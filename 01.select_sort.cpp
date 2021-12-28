#include <iostream>
#include <SortTestHelper.h>
using namespace std;

/**
 * ѡ������
 * @param arr ����������
 * @param n ����ĳ���
 */
template<typename T>
void selectionSort(T arr[], int n) {
  for (int i = 0; i < n; ++i) {
    // Ѱ��[i, n)���������Сֵ
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
 * O��n^2���������㷨
 * ���㷨�������㷨�Ļ���������򵥣�����ʵ�֣���һЩ���龰����ѡ��
 * ��һЩ���������£��򵥵������㷨����Ч��
 * �򵥵������㷨˼�����������ӵ������㷨��
 * ��Ϊ�ӹ��̣��Ľ������ӵ������㷨��
 * @return
 */
int main() {
  int n = 10000;
  int *arr = SortTestHelper::generateRandomArray(n, 0, n);
  SortTestHelper::testSort("Selection Sort", selectionSort, arr, n);
  delete[] arr;
  return 0;
}
