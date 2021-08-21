#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time_utils.h>
#include "io_utils.h"


/**
 * 获取系统时间
 * @return
 */
int main(void) {
  time_t current_time;

  time(&current_time);
  PRINT_INT(current_time);

  current_time = time(NULL);
  PRINT_INT(current_time);

  PRINT_LLONG(TimeInMillisecond());
  return 0;
}
