#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_utils.h"


/**
 * 内存操作函数 及 C99的restrict关键字
 * 对字符串修改，确保2个指针指向的内存不重叠用restrict修饰
 * @return
 */
int main(void) {
//  memcpy();
//  memchr();
//  memcmp();

  char *mem = malloc(10);
  memset(mem, 0, 10);
  PRINT_INT_ARRAY(mem, 10);
  free(mem);

//  memmove();
  char src[] = "HelloWorld";
  char *dest = malloc(11);
  memset(dest, 0, 11);
  memcpy(dest, src, 11); // 内存不重叠
  puts(dest);
  memmove(dest + 3, dest + 1, 4); // 内存重叠
  puts(dest);
  free(dest);
  return 0;
}
