#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"


int IsBigEndian() {
  union {
    char c[2];
    short s;
  } value = {.s=0x100};
  return value.c[0] = 1;
}

int IsBigEndian2() {
  short s = 0x100;
  char *p = (char *)&s;
  return p[0] == 1;
}

int ToggleEndian(int original) {
  union {
    char c[4];
    int i;
  } value = {.i = original};
  char temp = value.c[0];
  value.c[0] = value.c[3];
  value.c[3] = temp;
  temp = value.c[1];
  value.c[1] = value.c[2];
  value.c[2] = temp;
  return value.i;
}

int ToggleEndian2(int original) {
  char *p = (char *)&original;
  char temp = p[0];
  p[0] = p[3];
  p[3] = temp;
  temp = p[1];
  p[1] = p[2];
  p[2] = temp;
  return original;
}

/**
 * 判断字节序
 *
 * 字节序与CPU内存读取的方式有关
 * 例如 01 02 03 04内存地址
 * 小端序： 0x04030201
 * 大端序：0x01020304 符合人类阅读顺序
 * @return
 */
int main(void) {
  PRINT_INT(IsBigEndian());
  int original = 0x12345678;
  PRINT_HEX(ToggleEndian(original));
  return 0;
}
