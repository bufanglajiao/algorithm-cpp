#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"

void Echo() {
#define BUFFER_SIZE 4
  int buffer[BUFFER_SIZE];
  while(1) {
    size_t bytes_read = fread(buffer, sizeof(buffer[0]), BUFFER_SIZE,stdin);
    if(bytes_read < BUFFER_SIZE) {
      if(feof(stdin)) {
        puts("EOF");
        fwrite(buffer, sizeof(buffer[0]), bytes_read, stdout);
      } else if(ferror(stdin)) {
        perror("error read from stdin");
      }
      break;
    }
    fwrite(buffer, sizeof(buffer[0]), BUFFER_SIZE, stdout);
  }

}

/**
 * 读写指定大小的字节
 * 适合二进制文件、文本文件
 * fread fwrite
 * @return
 */
int main(void) {

  Echo();

  return 0;
}
