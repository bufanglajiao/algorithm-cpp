#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"

/**
 * 文件流的缓冲
 * @return
 */
int main(void) {
  FILE *file = fopen("README.md", "r");
//  char buf[BUFSIZ];
//  setbuf(file, buf);
//  setbuf(file, NULL);

  char buf[8192];

  if(file){
    setvbuf(file, buf, _IOLBF, 8192);
    puts("Open successfully");
    int err = ferror(file);
    PRINT_INT(err);
    int eof = feof(file);
    PRINT_INT(eof);
    fflush(stdout);

    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen ");
  }


  return 0;
}
