#include <iostream>
#include "SortTestHelper.h"

using namespace std;

/**
 * ���ֲ��ҷ�(�ǵݹ��)������������arr�У�����target
 * @tparam T
 * @param arr
 * @param n
 * @param target Ŀ��Ԫ�ص�������δ�ҵ��򷵻�-1
 * @return
 */
template<typename T>
int binarySearch(T arr[], int n, T target) {
  // ��arr[left...right]�в���target
  int left = 0, right = n - 1;
  while(left <= right) {
//    int middle = (left + right) / 2;
    int middle = left + (right-left)/2;//��ֹ���͵����
    if(arr[middle] == target) {
      return middle;
    }
    // ��arr[left...middle-1]�в���target
    if(target < arr[middle]) {
      right = middle - 1;
    } else {// ��arr[middle+1...right]�в���target
      left = middle + 1;
    }
  }
  return -1;
}

/**
 * ���ֲ��ҷ�(�ݹ��)������������arr�У�����target
 * @tparam T
 * @param arr
 * @param l
 * @param r
 * @param target Ŀ��Ԫ�ص�������δ�ҵ��򷵻�-1
 * @return
 */
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){
  if( l > r )
    return -1;
  //int mid = (l+r)/2;
  // ��ֹ��������µ����������ʹ��������߼����mid
  int mid = l + (r-l)/2;
  if( arr[mid] == target )
    return mid;
  else if( arr[mid] > target )
    return __binarySearch2(arr, l, mid-1, target);
  else
    return __binarySearch2(arr, mid+1, r, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target){
  return __binarySearch2( arr , 0 , n-1, target);
}

/**
 * ���ֲ��ҷ���logn��
 * ����������У�����ʹ�ö��ֲ��ҷ���
 * @return
 */
int main() {
  return 0;
}

