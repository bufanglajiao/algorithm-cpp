#include <iostream>
#include <Student.h>
#include <SortTestHelper.h>
using namespace std;


/**
 * ��������
 * @param arr ����������
 * @param n ����ĳ���
 */
template<typename T>
void insertionSort2(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    // Ѱ��Ԫ��arr[i]���ʵĲ���λ��
    for (int j = i; j > 0 && arr[j] < arr[j-1]; --j) {
      swap(arr[j], arr[j-1]);
    }
  }
}
/**
 * ���������Ż���һ�θ�ֵ
 * @param arr ����������
 * @param n ����ĳ���
 */
template<typename T>
void insertionSort(T arr[], int n) {
  for (int i = 1; i < n; ++i) {
    // Ѱ��Ԫ��arr[i]���ʵĲ���λ��
    T e = arr[i];
    int j; // ����Ԫ��eӦ�ò����λ��
    for (j = i; j > 0 && arr[j - 1] > e; --j) {
      arr[j] = arr[j-1];
    }
    arr[j] = e;
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
  int *arr2 = SortTestHelper::generateNearlyOrderedArray(n, 100);
  SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);
  SortTestHelper::testSort("Insertion Sort(NearlyOrderedArray)", insertionSort, arr2, n);
  delete[] arr;
  delete[] arr2;
  return 0;
}
