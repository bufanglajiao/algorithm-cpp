#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <tinycthread.h>
#include "io_utils.h"

atomic_int count = 0;

atomic_flag resume_flag = ATOMIC_FLAG_INIT;
int PrintNumbers(void *args) {
  int current = 0;
  while(atomic_flag_test_and_set(&resume_flag)) {
    current++;
    PRINT_INT(current);
    thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);
  }
  return current;
}

int Counter(void *arg) {
  PRINTLNF("Counter.");
  for (int i = 0; i < 1000000; ++i) {
    count++;
    // int temp = count, count = temp + 1, temp;
  }
  return 0;
}

/**
 * 资源的线程安全问题
 * @return
 */
int main(void) {
  thrd_t t_1, t_2;
  thrd_create(&t_1, Counter, NULL);
  thrd_create(&t_2, Counter, NULL);
  thrd_join(t_1, NULL);
  thrd_join(t_2, NULL);
  PRINT_INT(count);

  atomic_flag_test_and_set(&resume_flag);
  thrd_t t;
  thrd_create(&t, PrintNumbers, NULL);
  thrd_sleep(&(struct timespec){.tv_sec=6}, NULL);

  atomic_flag_clear(&resume_flag);
  int last_number;
  thrd_join(t, &last_number);
  PRINT_INT(last_number);
  return 0;
}
