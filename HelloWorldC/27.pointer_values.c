#include <stdio.h>
#include "io_utils.h"

int *pointer_at_large;

void DangerousPointer() {
  int a = 2; // 自动变量，函数退出即销毁
  pointer_at_large = &a;
  // ...
  pointer_at_large = NULL;
}

/**
 * 特殊的指针
 * 1. 不要将硬编码赋值给指针
 * 2. 空指针NULL的用法
 * 3. 注意避免产生野指针
 * @return
 */
int main(void) {
//  int *p = (int *)100;
//  PRINT_INT(p);
//  PRINT_HEX(&p);
//  PRINT_INT(*p);

  int *p = NULL;
//  *p = 3;
  if(p) {

  }

  DangerousPointer();
  if(pointer_at_large){
    PRINT_INT(*pointer_at_large);
  }

  return 0;
}
