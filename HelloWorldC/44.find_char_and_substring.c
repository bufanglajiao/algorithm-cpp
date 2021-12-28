#include <stdio.h>
#include <string.h>
#include "io_utils.h"


/**
 * 查找字符与子串
 * @return
 */
int main(void) {
  // 查找字符strchr
  char *string = "Hello World!";
  char *result = strchr(string, 'l');
  char *result_reverse = strrchr(string, 'l');
  puts(result);
  puts(result_reverse);

  // 查找子串strstr
  char *substring_position = strstr(string, "Wor");
  puts(substring_position);
  PRINT_INT(substring_position - string);

  // 查找字符strpbrk
  char *string2 = "C, 1972; C++, 1983; Java, 1995; Rust, 2010; Kotlin, 2011";
  char *break_set = ",;";
  int count = 0;
  char *p = string2;
  do {
    p = strpbrk(p, break_set);
    if(p){
      puts(p);
      p++;
      count++;
    }
  } while(p);
  PRINTLNF("Found %d characters.", count);
  return 0;
}
