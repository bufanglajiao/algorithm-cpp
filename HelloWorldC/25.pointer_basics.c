#include <stdio.h>
#include "io_utils.h"

/**
 * 指针的基础
 * @return
 */
int main(void) {
  int a;
  scanf("%d", &a);

  int *p = &a;
  PRINT_HEX(p);
  PRINT_HEX(&a);

  PRINT_INT(sizeof(int *));

  PRINT_INT(*p);
  PRINT_INT(a);

  int **pp = &p;
  // *pp => p;

  return 0;
}
