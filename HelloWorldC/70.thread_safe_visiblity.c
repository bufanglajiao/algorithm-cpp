#include <stdio.h>
#include <stdlib.h>
#include <tinycthread.h>
#include "io_utils.h"


volatile int flag = 0;
volatile int a = 0;
int x = 0;

int T1(void *arg) {
  a = 2;
  flag = 1;
  a = a + 3;
  return 0;
}

int T2(void *arg) {
  while(!flag) {}
  x = a * a;
  return 0;
}

/**
 * 资源的线程安全问题
 * 1. 对共享资源进行非原子的并发访问
 * 2. 不同线程之间的代码可见性问题
 * 3. 线程内部代码编译时的重排序问题
 *
 * volatile:
 * 1. 禁止代码重排序，禁止编译器优化读写操作
 * 2. 并非为并发程序设计
 * 3. 不会保证访问的原子性
 * 4. 与java的volatile不同
 * 5. MSVC赋予强制刷新缓存的语义，可以保证可见性
 *
 * @return
 */
int main(void) {
  thrd_t t_1, t_2;
  thrd_create(&t_1, T1, NULL);
  thrd_create(&t_2, T2, NULL);
  thrd_join(t_1, NULL);
  thrd_join(t_2, NULL);
  PRINT_INT(x);

  return 0;
}
