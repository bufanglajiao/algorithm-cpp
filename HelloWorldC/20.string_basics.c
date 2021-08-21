#include <stdio.h>
#include "io_utils.h"

/**
 * 字符串
 * @return
 */
int main(void) {
  char string[12] = "Hello World";
  char string2[] = "Hello World";
  for (int i = 0; i < 11; ++i) {
    PRINT_CHAR(string[i]);
  }

  // NULL \0
  PRINTLNF("%s", string);

  char string_zh[] = "你好，中国";
  wchar_t ws[] = L"你好，中国";

  return 0;
}
