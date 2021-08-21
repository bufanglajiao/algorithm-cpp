#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>
#include "io_utils.h"

#ifdef __unix__
#include <sys/time.h>
#endif

/**
 * 时间的基本概念
 * 1. UTC是世界调和时间，是国际时间的标准，提及UTC时，它一定是一个确定的值，
 *    不受时区的影响。
 * 2. GMT是格林威治时间，与UTC的时间是一致的，但说起GMT的时候其实指的就是
 *    零时区的时间，它现在已经不是时间标准了。
 * 3. Epoch, 一般被翻译为纪元，时代，通常在计算机程序中使用的时间都是从UTC时间
 *    1970年1月1日0时9分0秒开始的一个整数值，这是Unix的计时方法，Unix系统上对
 *    C标准的扩展标准POSIX也采用了这样的规定，因此这个起始时间就被称为Unix Epoch。
 *    现绝大多数编程语言例如Java、JS等都采用了Unix Epoch，Windows上的C实现也是如此。
 * @return
 */
int main(void) {
  time_t; // 从epoch开始计算的时间
  clock_t ; // 程序运行的时间
  struct tm;
  struct timespec; // C11 MSVC 纳秒
  struct timeb; // 毫秒
#ifdef __unix__
  struct timeval; // 微秒
#endif

  return 0;
}
