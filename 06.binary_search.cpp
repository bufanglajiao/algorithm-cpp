#include <iostream>
#include "SortTestHelper.h"

using namespace std;

/**
 * 二分查找法(非递归版)，在有序数组arr中，查找target
 * @tparam T
 * @param arr
 * @param n
 * @param target 目标元素的索引，未找到则返回-1
 * @return
 */
template<typename T>
int binarySearch(T arr[], int n, T target) {
  // 在arr[left...right]中查找target
  int left = 0, right = n - 1;
  while(left <= right) {
//    int middle = (left + right) / 2;
    int middle = left + (right-left)/2;//防止类型的溢出
    if(arr[middle] == target) {
      return middle;
    }
    // 在arr[left...middle-1]中查找target
    if(target < arr[middle]) {
      right = middle - 1;
    } else {// 在arr[middle+1...right]中查找target
      left = middle + 1;
    }
  }
  return -1;
}

/**
 * 二分查找法(递归版)，在有序数组arr中，查找target
 * @tparam T
 * @param arr
 * @param l
 * @param r
 * @param target 目标元素的索引，未找到则返回-1
 * @return
 */
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){
  if( l > r )
    return -1;
  //int mid = (l+r)/2;
  // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
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
 * 二分查找法（logn）
 * 针对有序数列，才能使用二分查找法。
 * @return
 */
int main() {
  return 0;
}

