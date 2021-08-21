#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <sys/stat.h>
#include "io_utils.h"

long GetFileSize(char const *filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_size;
}

int IsDirectory(char const *filename) {
  struct stat st;
  stat(filename, &st);
  return st.st_mode & S_IFDIR;
}

/**
 * 其他的文件操作
 * @return
 */
int main(void) {
//  remove();
//  rename("", "");

  FILE *file = tmpfile();
//  tempnam()
  fclose(file);


  return 0;
}
