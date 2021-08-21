#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "io_utils.h"

//#pragma pack(2)
/**
 * 结构体的内存对齐
 * @return
 */
int main(void) {
  typedef struct Person {
    char *name;
    int age;
    char *id;
  }Person;

  struct Person person = {.name="yinlei", .id="120"};
  PRINT_INT(person.age);
  person.age =23;

  typedef struct {
    char a; //1
    char b; //1
//    __attribute((aligned(2))) int c; // 4 gcc only
//    _Alignas(4) int c; // 4 c11
    int c; // 4
    short d; // 2
    double e; //8
  } Align;

  typedef struct {
    char a; //1
    char b; //1
    short d; // 2
    int c; // 4
    double e; //8
  } OptimizedAlign;

  Align align = {'a', 'b', 3, 4, 5.0};
//  PRINT_INT(_Alignof(align.c));
  PRINT_INT(offsetof(Align, c));
  return 0;
}
