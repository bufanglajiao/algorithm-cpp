#include <stdio.h>

#ifdef __cplusplus
extern "C"{
#endif
  // ...
#ifdef __cpluscplus
};
#endif

// or: target_compile_definitions(${name} PUBLIC DEBUG)
//#define DEBUG
void dump(char *message){
#ifdef DEBUG
  puts(message);
#endif
}

/**
 * 条件编译
 * 1. #ifdef 如果定义了
 * 2. #ifndef 如果没定义
 * 3. #if 如果
 * #endif
 *
 * if defined(MACRO) ==> #ifdef MACRO
 * @return
 */
int main(void) {
  dump("main start");
  printf("Hello world");
  dump("main end");

  printf("__STDC_VERSION__: %ld\n", __STDC_VERSION__);

#if __STDC_VERSION__ >= 201112
  puts("C11!");
#elif __STDC_VERSION__ >= 199901
  puts("C99!");
#else
    puts("Maybe C90?");
#endif

  return 0;
}
