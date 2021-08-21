#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time_utils.h>
#include "io_utils.h"

#define PI 3.1415926

void DoHardWork(){
  double sum = 0;
  for (int i = 0; i < 100000000; ++i) {
    sum += i * i / PI;
  }
  PRINT_DOUBLE(sum);
}

/**
 * 计算时间差
 * clock()返回的是处理器消耗的时间，更能真实的反映程序运行的消耗
 * time()返回的是系统时间，更适合描述真实世界的时间变化
 * @return
 */
int main(void) {

  time_t start_time = time(NULL);
  DoHardWork();
  time_t end_time = time(NULL);
  double diff = difftime(start_time, end_time);
  PRINT_DOUBLE(diff);

  long_time_t start_time_ms = TimeInMillisecond();
  DoHardWork();
  long_time_t end_time_ms = TimeInMillisecond();
  PRINT_LLONG(end_time_ms - start_time_ms);

  clock_t start_time_c = clock();
  DoHardWork();
  clock_t end_time_c = clock();
  PRINT_DOUBLE((end_time_c - start_time_c) * 1.0 / CLOCKS_PER_SEC);

  return 0;
}
