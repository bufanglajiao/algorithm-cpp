#include <stdio.h>

// x: 形参
double F(double x) {
  return x * x + x + 1;
}

double G(double x, double y, double z) {
  return x * x + y * y + z * z;
}

/**
 * 函数基础
 * @return
 */
int main(void) {
 /**
  * <return type> <name>(<parameters>) {
  * ...statement
  * return <return value>
  * }
  */

 // 2.0实参
 double result_f = F(2.0);
 double result_g = G(3.0, 4.0, 5.0);
  printf("result of f: %f\n", result_f);
  printf("result of g: %f\n", result_g);

//  H();
  return 0;
}

double H(double x) {
  return x;
}