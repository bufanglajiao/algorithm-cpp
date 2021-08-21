#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include "io_utils.h"


/**
 * 字符串与其他数值类型的转换
 * atox: 使用简单，适用于简单、要求不高的场景
 * strtox：可重复解析，更安全，功能更多
 * @return
 */
int main(void) {
  PRINT_INT(atoi("1234"));//1234
  PRINT_INT(atoi("-1234"));//-1234
  PRINT_INT(atoi("    1234abcd"));//1234
  PRINT_INT(atoi("0x10"));//0

  PRINT_DOUBLE(atof("12.34"));//12.34
  PRINT_DOUBLE(atof("-12e34"));//-1.2e+35
  PRINT_DOUBLE(atof("    1.234abcd"));//1.234
  PRINT_DOUBLE(atof("0x10"));//16
  PRINT_DOUBLE(atof("0x10p3.9"));//128

  char const *const kInput = "1 2000000000000000000000000000 3 -4 5abcd bye";
  PRINTLNF("Parse: %s", kInput);
  char const *start = kInput;
  char *end;
  while(1){
    errno = 0;

    const long i = strtol(start, &end, 10);
    if(start == end) {
      break;
    }
    printf("'%.*s'\t ==> %ld.", (int)(end-start), start, i);

    if(errno == ERANGE) {
      perror("");
    }
    putchar('\n');
    start = end;
  }
  PRINTLNF("left: %s", end);
  return 0;
}
