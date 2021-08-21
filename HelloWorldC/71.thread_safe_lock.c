#include <stdio.h>
#include <stdlib.h>
#include <tinycthread.h>
#include "io_utils.h"

int count = 0;
mtx_t mutex;

int Counter(void *arg) {
  PRINTLNF("Counter.");
  for (int i = 0; i < 1000000; ++i) {
    mtx_lock(&mutex);
    count++;
    mtx_unlock(&mutex);
    // int temp = count, count = temp + 1, temp;
  }
  return 0;
}

/**
 * 资源的线程安全问题
 * @return
 */
int main(void) {
  mtx_init(&mutex, mtx_plain);
  thrd_t t_1, t_2;
  thrd_create(&t_1, Counter, NULL);
  thrd_create(&t_2, Counter, NULL);
  thrd_join(t_1, NULL);
  thrd_join(t_2, NULL);
  PRINT_INT(count);
  mtx_destroy(&mutex);
  return 0;
}
