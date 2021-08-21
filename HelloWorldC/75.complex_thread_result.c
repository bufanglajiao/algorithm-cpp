#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <tinycthread.h>
#include "io_utils.h"

typedef struct {
  int a;
  char *b;
} ComplexResult;

typedef struct {
  int arg;
  ComplexResult result;
} ComplexArg;


int ComplexReturnValue(ComplexArg *arg){
  ComplexResult *complex_result = &arg->result; // 指针指向该result并修改
  complex_result->a = 2;
  complex_result->b = "helloWorld";
  return 0;
}

/**
 * 处理复杂的线程返回结果
 * @return
 */
int main(void) {
  ComplexArg complex_arg= {.arg=1};
  thrd_t t;
  thrd_create(&t, ComplexReturnValue, &complex_arg);

  thrd_join(t, NULL);
  ComplexResult  *complex_result = &complex_arg.result;
  PRINT_INT(complex_result->a);
  puts(complex_result->b);
  return 0;
}
