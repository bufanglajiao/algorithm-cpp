#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <time_utils.h>
#include "io_utils.h"


/**
 * 获取日历时间(和机器本地时区有关)
 * @return
 */
int main(void) {
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


  calendar_time->tm_sec = 70;

  // 日历时间转为时间戳
  time_t current_time2 = mktime(calendar_time);
  PRINT_INT(calendar_time->tm_year);//121
  PRINT_INT(calendar_time->tm_mon);//7
  PRINT_INT(calendar_time->tm_mday);//21
  PRINT_INT(calendar_time->tm_hour);//15
  PRINT_INT(calendar_time->tm_min);//43
  PRINT_INT(calendar_time->tm_sec);//10


  // 获取零时区时间
  struct tm *gmt = gmtime(&current_time);
  PRINT_INT(gmt->tm_year);//121
  PRINT_INT(gmt->tm_mon);//7
  PRINT_INT(gmt->tm_mday);//21
  PRINT_INT(gmt->tm_hour);//7
  PRINT_INT(gmt->tm_min);//44
  PRINT_INT(gmt->tm_sec);//13

  return 0;
}
