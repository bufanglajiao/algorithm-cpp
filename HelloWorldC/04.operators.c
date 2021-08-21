#include <stdio.h>

/**
 * 运算符
 * @return
 */
int main() {
  int first = 0;
  int second;
  int third;

  // =
  third = second = first;

  int left, right;
  left = 2;
  right = 3;
  int sum;
  sum = left + right; // 5
  int diff = left - right; // -1
  int product = left * right; // 6
  int quotient = left / right; // 0
  float quotient_float = left * 1.f / right;// 0.666667
  int remainder = left % right; // 2

  int quotient_1 = 100 / 30; // 3
  printf("sum: %d\n", sum);
  printf("diff: %d\n", diff);
  printf("product: %d\n", product);
  printf("quotient: %d\n", quotient);
  printf("quotient_float: %f\n", quotient_float);
  printf("remainder: %d\n", remainder);
  printf("quotient_1: %d\n", quotient_1);

  // > < >= <= == !=
  // true: 1 false: 0
  printf("3 > 2: %d\n", 3 > 2);
  printf("3 < 2: %d\n", 3 < 2);
  printf("3 >= 2: %d\n", 3 >= 2);
  printf("3 <= 2: %d\n", 3 <= 2);
  printf("3 == 2: %d\n", 3 == 2);
  printf("3 != 2: %d\n", 3 != 2);

  // && || 短路
  printf("3 > 2 && 3 < 2: %d\n", 3 > 2 && 3 < 2);
  printf("3 > 2 || 3 < 2: %d\n", 3 > 2 || 3 < 2);

  // ++ --
  int i = 1;
  int j = i++; // j = 1, i = 2
  int k = ++i; // k = 3, i = 3
  printf("i: %d\n", i);
  printf("j: %d\n", j);
  printf("k: %d\n", k);

  // bit operators & | ^ ~
  // &: 相同为1， 不同为0
  // |: 有1为1， 全0为0
  // ^: 不同为1， 相同为0
  // ~: 1得0， 0得1
#define FLAG_VISIBLE 0x1 // 2^0, 0001
#define FLAG_TRANSPARENT 0x2 // 2^1, 0010
#define FLAG_RESIZABLE 0x4 // 2^2, 0100
  int window_flags = FLAG_RESIZABLE | FLAG_TRANSPARENT;// 0110
  int resizable = window_flags & FLAG_RESIZABLE; // 0100
  int visible = window_flags & FLAG_VISIBLE; // 0000

  // << >>
  int x = 1000;
  x << 1;
  x >> 1;

  x *= 2;
  x /= 2;
  x += 2;
  x -= 2;
  x %= 2;
  x >>= 1;
  x <<= 1;

  x = x * 2, x = x + 3; // 逗号运算符，结果是后面的那个表达式的值

  return 0;
}
