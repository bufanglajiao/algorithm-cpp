#include <stdio.h>
#include <stdlib.h>
#include <tinycthread.h>
#include "io_utils.h"

tss_t count_key;

void MyFree(void *ptr) {
  PRINTLNF("Free %#x", ptr);
  free(ptr);
}

int Counter(int *step) {
  int *count = malloc(sizeof(int));
  *count = 0;
  if(tss_set(count_key, count) == thrd_success){
    for (int i = 0; i < 1000000; ++i) {
      *count += *step;
    }
  }
  PRINT_INT(*count);
  PRINT_INT(*((int *)tss_get(count_key)));
  return 0;
}

/**
 * 资源的线程安全问题
 * 开辟线程私有内存
 * 要解决问题，首先想到的就是解决制造问题的人
 * @return
 */
int main(void) {
  if(tss_create(&count_key, MyFree) == thrd_success){
    thrd_t t_1, t_2;
    int step_1 = 1, step_2 = 2;
    thrd_create(&t_1, Counter, &step_1);
    thrd_create(&t_2, Counter, &step_2);
    thrd_join(t_1, NULL);
    thrd_join(t_2, NULL);
    puts("t_1/t_2 ended.");
    tss_delete(count_key);
    PRINTLNF("count_key deleted");
  }
  return 0;
}
