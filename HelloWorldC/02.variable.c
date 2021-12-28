#include <stdio.h>

/**
 * 变量
 * 变量命名规则
 * 1. a-zA-Z0-9_
 * 2. 数不能在第一个
 * 3. Google code style.
 * @return
 */
int main() {
  // <type> <name>;
  int value;
  // <type> <name> = <initialized value>
  int value_init = 3;

  value = 4;
  value_init = 5;

  printf("value: %d\n", value);
  value_init = value;

  printf("size of value: %d\n", sizeof(value));
  printf("address of value: %#x\n", &value);
  return 0;
}
