#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"


#define BUFFER_SIZE 1024
#define COPY_SUCCESS 0
#define COPY_ILLEGAL_ARGUMENTS -1
#define COPY_SRC_OPEN_ERROR -2
#define COPY_SRC_READ_ERROR -3
#define COPY_DEST_OPEN_ERROR -4
#define COPY_DEST_WRITE_ERROR -5
#define COPY_UNKNOWN_ERROR -100

int CopyFile1(char const *src, char const *dest) {
  if(!src || !dest) {
    return COPY_ILLEGAL_ARGUMENTS;
  }
  FILE *src_file = fopen(src, "r");
  if(!src_file) {
    return COPY_SRC_OPEN_ERROR;
  }
  FILE *dest_file = fopen(dest, "w");
  if(!dest_file) {
    fclose(src_file);
    return COPY_DEST_OPEN_ERROR;
  }
  int result;
  while(1) {
    int next = fgetc(src_file);
    if(next == EOF) {
      if(ferror(src_file)){
        result = COPY_SRC_READ_ERROR;
      } else if(feof(src_file)) {
        result = COPY_SUCCESS;
      } else {
        result = COPY_UNKNOWN_ERROR;
      }
      break;
    }
    if(fputc(next, dest_file) == EOF) {
      result = COPY_DEST_WRITE_ERROR;
      break;
    }
  }
  fclose(src_file);
  fclose(dest_file);
  return result;
}

int CopyFile2(char const *src, char const *dest) {
  if(!src || !dest) {
    return COPY_ILLEGAL_ARGUMENTS;
  }
  FILE *src_file = fopen(src, "r");
  if(!src_file) {
    return COPY_SRC_OPEN_ERROR;
  }
  FILE *dest_file = fopen(dest, "w");
  if(!dest_file) {
    fclose(src_file);
    return COPY_DEST_OPEN_ERROR;
  }
  int result = COPY_SUCCESS;
  char buffer[BUFFER_SIZE];
  char *next;
  while(1) {
    next = fgets(buffer, BUFFER_SIZE, src_file);
    if(!next) {
      if(ferror(src_file)){
        result = COPY_SRC_READ_ERROR;
      } else if(feof(src_file)) {
        result = COPY_SUCCESS;
      } else {
        result = COPY_UNKNOWN_ERROR;
      }
      break;
    }
    if(fputs(next, dest_file) == EOF) {
      result = COPY_DEST_WRITE_ERROR;
      break;
    }
  }
  fclose(src_file);
  fclose(dest_file);
  return result;
}

int CopyFile3(char const *src, char const *dest) {
  if(!src || !dest) {
    return COPY_ILLEGAL_ARGUMENTS;
  }
  FILE *src_file = fopen(src, "rb");
  if(!src_file) {
    return COPY_SRC_OPEN_ERROR;
  }
  FILE *dest_file = fopen(dest, "wb");
  if(!dest_file) {
    fclose(src_file);
    return COPY_DEST_OPEN_ERROR;
  }
  int result = COPY_SUCCESS;
  char buffer[BUFFER_SIZE];
  while(1) {
    size_t bytes_read = fread(buffer, sizeof(buffer[0]), BUFFER_SIZE, src_file);
    if(fwrite(buffer, sizeof(buffer[0]), bytes_read, dest_file) < bytes_read ) {
      result = COPY_DEST_WRITE_ERROR;
      break;
    }
    if(bytes_read<BUFFER_SIZE) {
      if(ferror(src_file)){
        result = COPY_SRC_READ_ERROR;
      } else if(feof(src_file)) {
        result = COPY_SUCCESS;
      } else {
        result = COPY_UNKNOWN_ERROR;
      }
      break;
    }
  }
  fclose(src_file);
  fclose(dest_file);
  return result;
}
/**
 * 3个版本的复制文件
 * @return
 */
int main(void) {
  int result = CopyFile1("data/factorial.h", "data_copy/factorial.h");
  PRINT_INT(result);
  result = CopyFile1("data/boy.png", "data_copy/boy.png");
  PRINT_INT(result);

  result = CopyFile2("data/factorial.h", "data_copy/factorial2.h");
  PRINT_INT(result);

  result = CopyFile3("data/factorial.h", "data_copy/factorial3.h");
  PRINT_INT(result);
  result = CopyFile3("data/boy.png", "data_copy/boy3.png");
  PRINT_INT(result);

  return 0;
}
