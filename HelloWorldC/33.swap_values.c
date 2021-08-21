#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_utils.h"

void SwapInt(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void Swap(void *first, void *second, size_t size) {
  void *temp = malloc(size);
  if(temp){
    memcpy(temp, first, size);
    memcpy(first, second, size);
    memcpy(second, temp, size);
    free(temp);
  }else {

  }
}

// 在调用处展开
// msvc c++ decltype(a)
#define SWAP(a, b) do{typeof(a) temp = a; a = b; b = temp;}while(0)

/**
 * 交换2个变量的值
 * @return
 */
int main(void) {
  int a = 0;
  int b = 1;

  int c = 2;
  int d = 3;

  double x = 3.0;
  double y = 4.0;

  // swap
  SwapInt(&a, &b);
//  SwapInt(&x, &y);
  Swap(&x, &y, sizeof(double ));

  if (a) SWAP(c, d); else {

  }

  PRINT_INT(a);
  PRINT_INT(b);
  PRINT_INT(c);
  PRINT_INT(d);
  PRINT_DOUBLE(x);
  PRINT_DOUBLE(y);
  return 0;
}
