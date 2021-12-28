#include <stdio.h>
#include <stdarg.h>

void Printlnf(const char* format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

#define PRINTLNF(format, ...) printf("("__FILE__":%d) %s : "format"\n", __LINE__, __FUNCTION__ ,##__VA_ARGS__)

#define PRINT_INT(value) PRINTLNF(#value": %d", value)

/**
 * 宏函数实现printlnf函数
 * @return
 */
int main(void) {
  int value = 23;
  Printlnf("Hello World! %d", value);
  PRINTLNF("Hello World! %d", value);
  PRINTLNF("Hello World!");

  PRINT_INT(value);// value: 23
  PRINT_INT(3+4);// 3+4: 7

  return 0;
}
