#include <stdio.h>

void EmptyParamList();

int Add(int, int);
/**
 * 函数原型
 * 1. 函数名
 * 2. 函数返回值类型，默认为int
 * 3. 函数参数列表：参数类型、参数顺序，和参数形参名不重要
 * @return
 */
int main(void) {
  EmptyParamList();
  EmptyParamList(1);
  EmptyParamList("Hello");
  int result = Add(1, 2);
  return 0;
}

void EmptyParamList() {// 明确不要参数，需要加void
  puts("helloo");
}
