#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include "io_utils.h"

/**
 * 输入输出流的位置
 * @return
 */
int main(void) {
  FILE *file = fopen("CMakeLists.txt", "rb");
  long position = ftell(file);
  PRINT_LONG(position);
  char buffer[100];
  fread(buffer, 1, 100, file);
  PRINT_LONG(ftell(file));

  fseek(file, 10, SEEK_SET);
  PRINT_LONG(ftell(file));
  fseek(file, 10, SEEK_CUR);
  PRINT_LONG(ftell(file));
  fseek(file, -10, SEEK_END);
  PRINT_LONG(ftell(file));
  fclose(file);

  return 0;
}
