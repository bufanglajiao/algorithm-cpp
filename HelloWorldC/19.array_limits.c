#include <stdio.h>
#include "io_utils.h"


#define ARRAY_SIZE 5
/**
 * 数组的边界
 * @return
 */
int main(void) {
  int array[ARRAY_SIZE];
  PRINT_INT(array[0]);
  PRINT_INT(array[5]);

  int value = 2;
  /**
   * 变长数据VLA
   * 数组的长度可以用变量来声明的数组
   * c语言标准从C99开始支持该特性
   * GCC提供了相应的扩展，MSVC不支持
   */
  int array_size_of_value[value];

  const int kSize = 5;// C++ OK, C++中,const是真的常量
  int array_size_of_const[kSize];


  // array[5] => array + 5
  return 0;
}
