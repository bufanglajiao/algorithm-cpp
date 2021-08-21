#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"


/**
 * 字符串的长度与比较
 * @return
 */
int main(void) {
  char *string = "Hello World!";
  PRINT_INT(strlen(string));
//  PRINT_INT(strnlen_s(string, 100));  // c11 msvc
//  PRINT_INT(strnlen(string, 100)); // gcc

  char *left = "Hello World!";
  char *right = "Hello C Programmers!";
  PRINT_INT(strcmp(left, right));
  PRINT_INT(strncmp(left, right, 5));

  return 0;
}
