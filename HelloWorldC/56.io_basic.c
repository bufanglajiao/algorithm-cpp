#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"

/**
 * 输入输出流
 * @return
 */
int main(void) {
  FILE *file = fopen("README.md", "r");
  if(file){
    puts("Open successfully");
    int err = ferror(file);
    PRINT_INT(err);
    int eof = feof(file);
    PRINT_INT(eof);

    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen ");
  }

  // 错误码
  for (int i = 0; i < 10; ++i) {
    PRINT_INT(i);
    puts(strerror(i));
  }

  stderr;
  stdin;
  stdout;

  return 0;
}
