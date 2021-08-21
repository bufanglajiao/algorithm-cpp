#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"

void ReadFile(){
  FILE *file = fopen("README.md", "r");
  if(file){

    int next_char = getc(file);
    while(next_char != EOF) {
      putchar(next_char);
      next_char = getc(file);
    }
    fclose(file);
  } else {
    PRINT_INT(errno);
    puts(strerror(errno));
    perror("fopen ");
  }
}


/**
 * 读写一个字符
 * getchar getc fgetc
 * putchar putc fputc
 * @return
 */
int main(void) {

//  while(1) {
//    int next_input = getchar();
//    if(next_input == EOF) {
//      break;
//    } else if(next_input == '\n') {
//      continue;
//    }
////    printf("%c\n", next_input);
//    putchar(next_input);
//  }

 ReadFile();


  return 0;
}
