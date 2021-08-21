#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "io_utils.h"

#if defined(__APPLE__) || defined(__linux__)
#include <unistd.h>
#elif defined(_WIN32)
#include <io.h>
#endif

void RedirectStdout(char const *filename) {
  static int saved_stdout_no = -1;
  if(filename){
    if(saved_stdout_no == -1){
      saved_stdout_no = dup(fileno(stdout));
    }
    fflush(stdout);
    freopen(filename, "a", stdout);
  } else {
    if(saved_stdout_no != -1){
      fflush(stdout);
      dup2(saved_stdout_no, fileno(stdout));
      close(saved_stdout_no);
      saved_stdout_no = -1;
    }
  }
}

/**
 * 重定向标准输入输出流
 * @return
 */
int main(void) {
  // freopen 重定向回来就没戏了
//  freopen("output.log", "a",  stdout);
//  puts("this will be written to file 'output.log'");
//  fclose(stdout);

  // POSIX标准 有dup dup2 fileno close
  puts("1");
  RedirectStdout("output.log");
  puts("2");
  RedirectStdout(NULL);
  puts("3");
  RedirectStdout("output.log");
  puts("4");
  RedirectStdout(NULL);
  puts("end");
  return 0;
}
