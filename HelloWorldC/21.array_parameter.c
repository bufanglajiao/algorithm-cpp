#include <stdio.h>
#include "io_utils.h"

#define LENGTH 10
int SumIntArray(int array[], int length){
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += array[i];
  }
  return sum;
}

/**
 * 函数的数组类型的参数
 * @return
 */
int main(void) {
  int array[LENGTH] = {1, 4, 7, 0, 10, 33, 654, 392, 23, 43};
  PRINT_INT(SumIntArray(array, 10));
  return 0;
}
