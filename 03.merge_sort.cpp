#include <iostream>
#include "SortTestHelper.h"

using namespace std;

/**
 * ��arr[left...middle]��[middle+1...right]���й鲢
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
  // ��ʼ����iָ����벿�ֵ���ʼ����λ��l��jָ���Ұ벿����ʼ����λ��mid+1
  int i = left, j = middle+1;
  for (int k = left; k <= right; ++k) {// kָ����ʱ����
    if( i > middle ){  // �����벿��Ԫ���Ѿ�ȫ���������
      arr[k] = aux[j-left];
      j++;
    }
    else if( j > right ){  // ����Ұ벿��Ԫ���Ѿ�ȫ���������
      arr[k] = aux[i-left];
      i++;
    }
    else if( aux[i-left] < aux[j-left] ) {  // ��벿����ָԪ�� < �Ұ벿����ָԪ��
      arr[k] = aux[i-left];
      i++;
    }
    else{  // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
      arr[k] = aux[j-left];
      j++;
    }
  }

  delete[] aux;
}
/**
 * �ݹ�ʹ�ù鲢���򣬶�arr[left...right]��Χ��������
 * @tparam T
 * @param arr
 * @param left
 * @param right
 */
template<typename T>
void __mergeSort(T arr[], int left, int right) {
  if(left >= right) return; // ���Ž�Ӧ��������С��Χ��ʱ���ת�ò�������
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
 * �鲢���򷨣��Զ����£�����nlogn
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

