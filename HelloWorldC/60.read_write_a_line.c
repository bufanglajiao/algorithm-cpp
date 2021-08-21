#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"

void Echo() {
  char buffer[4];
  while(1) {
//    if(!gets_s(buffer, 4)) {
    if(!fgets(buffer, 4, stdin)) {
      break;
    }
    printf("%s", buffer);
  }
}

/**
 * 读写一行字符
 * 不适合二进制文件
 * gets fgets
 * puts fputs
 * @return
 */
int main(void) {

  Echo();
  return 0;
}
