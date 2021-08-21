#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "io_utils.h"

int IsDigit(char c) {
  return c >= '0' && c <= '9';
}

/**
 * 判断字符的类型(查表的过程)
 * https://en.cppreference.com/w/c/string/byte
 * @return
 */
int main(void) {
  PRINT_INT(isdigit('0'));
  PRINT_INT(isspace(' '));
  PRINT_INT(isalpha('a'));
  PRINT_INT(isalnum('a'));
  PRINT_INT(isalnum('1'));
  PRINT_INT(ispunct(','));

  return 0;
}
