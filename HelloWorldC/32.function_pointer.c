#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"

// 类型推断：cdecl.org
int *(f(int, double));
int (*f2)(int, double);
int *(*f3)(int, double);
int (*f5[])(int, double);

typedef int (*Func)(int, double);
int Add(int, double);

typedef int Boolean;
typedef int *IntPtr;

void InitPointer(int **ptr, int length, int default_value) {
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    (*ptr)[i] = default_value;
  }
}

/**
 * 函数指针与typedef
 * @return
 */
int main(void) {
  int *p;
  PRINT_HEX(&main);
  PRINT_HEX(&InitPointer);

  void (*func)(int **ptr, int length, int default_value) = &InitPointer;

  func(&p, 10, 0);
  InitPointer(&p, 10, 0);
  PRINT_INT_ARRAY(p, 10);

  (*func)(&p, 10, 0);
  (*InitPointer)(&p, 10, 0);

  free(p);

  Func func1 = &Add;
  func1(1, 3.0);
  return 0;
}
