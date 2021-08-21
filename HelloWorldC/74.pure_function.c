#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <tinycthread.h>
#include "io_utils.h"


int Counter(void *arg) {
  int local_count = 0;
  PRINTLNF("Counter.");
  for (int i = 0; i < 1000000; ++i) {
    local_count++;
  }
  return local_count;
}

/**
 * 副作用与纯函数
 * @return
 */
int main(void) {
  thrd_t t_1, t_2;
  thrd_create(&t_1, Counter, NULL);
  thrd_create(&t_2, Counter, NULL);
  int count = 0;
  int result;
  thrd_join(t_1, &result);
  count += result;
  thrd_join(t_2, &result);
  count += result;

  PRINT_INT(count);
  return 0;
}
