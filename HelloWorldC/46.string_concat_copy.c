#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_utils.h"


/**
 * 字符串的连接和复制
 * @return
 */
int main(void) {
  char src[] = "HelloWorld";
  char dest[20] = "C said:";
  strcat(dest, src);
  strcpy(dest + strlen(dest), src);
  puts(dest);


  return 0;
}
