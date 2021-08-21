#include <stdio.h>

// file scope
int global_var = 1;

void LocalStaticVar(void) {
  // 静态变量： 作用域全局、内存不会因函数退出而销毁，有默认值
  static int static_var;
  // 自动变量：函数、块作用域随着函数和块退出而销毁，没有默认值
  int non_static_var;

  printf("static var: %d\n", static_var++);
  printf("non static var: %d\n", non_static_var++);
}

void CleanMemory() {
  int eraser = -1;
}

double Add(double a, double b);
// proto scope
//double Sort(int size, int array[size]);

// 看汇编指令，compiler expoler插件，设置地址：https://godbolt.org
void PassByMemory(int parameter) {
  printf("%d\n", parameter);
}
void PassByRegister(register int parameter) {
  printf("%d\n", parameter);
}
/**
 * 变量类型和作用域
 * -858993460就是0Xcccccccc
 * 烫 的GBK编码是cccc
 *
 * 变量类型：自动变量auto 静态变量static 寄存器变量register
 * 作用域：函数原型作用域、函数作用域、文件作用域、块作用域
 * @return
 */
int main(void) {// function scope
  // 自动变量
  auto int value = 0;

  {// block scope
    auto int a = 0;
    printf("%d\n", a);
  }
//  printf("%d\n", a);

  if(value > 0) {
    int is_value_equals_0 = 0;
  } else {
    global_var = 2;
  }
//  is_value_equals_0

  LocalStaticVar();
  CleanMemory();
  LocalStaticVar();
  CleanMemory();
  LocalStaticVar();

  return 0;
}
