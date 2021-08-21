#include <stdio.h>
#include "io_utils.h"

/**
 * 只读指针变量与只读变量指针
 * const 从后往前念
 * 看固定的是数据还是指向
 * @return
 */
int main(void) {
  int a;
  int b;

  int *p = &a;
  PRINT_HEX(p);
  PRINT_HEX(&a);

  PRINT_INT(sizeof(int *));

  PRINT_INT(*p);
  PRINT_INT(a);

  int **pp = &p;
  // *pp => p;

  *p = 20;
  PRINT_INT(*p);
  PRINT_INT(a);

  int *const cp = &a;
  *cp = 2;
//  cp = &b;
  int const * cp2 = &a;
//  *cp2 = 2;
  cp2 = &b;
  int const *const ccp = &a;
//  ccp = &b;
//  *ccp = 2;

  return 0;
}
