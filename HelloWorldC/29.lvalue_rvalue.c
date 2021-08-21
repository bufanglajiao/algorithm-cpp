#include <stdio.h>
#include "io_utils.h"


/**
 * 左值和右值\
 * 左值：描述内存空间
 * 右值：描述值
 * @return
 */
int main(void) {
  int a;
  a = 2;

  int *p = &a;
  *p = 23;

  int b = *p;

//  &a = p;
//  *p + 1 = 3;
  int array[4] = {0};
  int *pa =array;
  *pa = 2;
  *pa++ = 3;
  *(pa + 2) = 4;
  PRINT_INT_ARRAY(array, 4);
  return 0;
}
