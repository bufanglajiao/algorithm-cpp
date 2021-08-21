#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time_utils.h>
#include "io_utils.h"


/**
 * 格式化时间(转为字符串)
 * https://zh.cppreference.com/w/c/chrono/strftime
 * @return
 */
int main(void) {
  long_time_t current_time_in_ms = TimeInMillisecond();
  int current_time_millisecond = current_time_in_ms % 1000;

  time_t current_time;
  time(&current_time);

  // 时间戳转为日历时间
  struct tm *calendar_time = localtime(&current_time);
  PRINT_INT(calendar_time->tm_year);//121
  PRINT_INT(calendar_time->tm_mon);//7
  PRINT_INT(calendar_time->tm_mday);//21
  PRINT_INT(calendar_time->tm_hour);//15
  PRINT_INT(calendar_time->tm_min);//38
  PRINT_INT(calendar_time->tm_sec);//10

  // Sat Aug 21 15:50:45 2021
  puts(asctime(calendar_time));
  puts(ctime(&current_time));

  // 2021-08-21 15:50:45
  char current_time_s[20];
  size_t size = strftime(current_time_s,20, "%Y-%m-%d %H:%M:%S", calendar_time);
  PRINT_INT(size);
  puts(current_time_s);

  // 20210821155045
  size_t size2 = strftime(current_time_s,20, "%Y%m%d%H%M%S", calendar_time);
  sprintf(current_time_s + 14, "%03d", current_time_millisecond);
  puts(current_time_s);
  return 0;
}
