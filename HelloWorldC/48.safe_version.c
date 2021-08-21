#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io_utils.h"


/**
 * C11的安全版本的函数
 * @return
 */
int main(void) {
#ifdef __STDC_LIB_EXT1__
  puts("support C11 safe version");
#else
  puts("No support C11 safe version");
#endif
  char dst[2];
  int error_no = strcpy_s(dst, 2, "Too long!");
  PRINT_INT(error_no); // 34
  if(error_no) {
    perror("strcpy_s returns: ");
  }

  return 0;
}
