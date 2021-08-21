#include <stdio.h>
#include <stdarg.h>

void HandleVarargs(int arg_count, ...) {
  // 1. 定义va_list用于获取变长参数
  va_list args;
  // 2. 开始遍历
  va_start(args, arg_count);
  for (int i = 0; i < arg_count; ++i) {
    // 3. 去除对应参数(valist, type)
    int arg = va_arg(args, int);
    printf("%d: %d\n", i, arg);
  }
  // 4. 结束遍历
  va_end(args);
}

/**
 * 函数的变长参数
 * @return
 */
int main(void) {
  HandleVarargs(4, 1,2,3,4);
  return 0;
}
