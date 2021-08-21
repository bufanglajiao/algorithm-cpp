#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"

typedef enum FileFormat {
  PNG, JPEG = 23, BMP, UNKNOWN
}FileFormat;

FileFormat GuessFormat(char *file_path){
  FILE *file = fopen(file_path, "rb");
  FileFormat file_format = UNKNOWN;
  if(file){
    char buffer[8] = {0};
    size_t bytes_count = fread(buffer, 1, 8, file);
    if(bytes_count == 8 ) {
      // bmp: 42 4D
      // png: 89 50 4E 47 0D 0A 1A 0A
      // jpeg: FF D8 FF E0
      if(*((short *) buffer) == 0x4D42){
        file_format = BMP;
      } else if(*((long long *) buffer) == 0x0A1A0A0D474E5089) {
        file_format = PNG;
      } else if(*((int *) buffer) == 0xE0FFD8FF) {
        file_format = JPEG;
      }

    }
    fclose(file);
  }
  return file_format;
}

/**
 * 枚举
 * @return
 */
int main(void) {
  FileFormat file_format = PNG;
  FileFormat file_format1 = 1;
  FileFormat file_format2 = 10;

  PRINT_INT(GuessFormat("images/c.jpg"));
  PRINT_INT(GuessFormat("images/c.png"));
  return 0;
}
