#include <stdio.h>
#include "io_utils.h"

// 查看汇编的寄存器: info register rbp
// 会发现SumIntArray()和main()中的sum不是同一个，是2次拷贝后的结果
int SumIntArray(int array[], int length) {
  int sum = 0;
  for (int i = 0; i < length; ++i) {
    sum += array[i];
  }
  return sum;
}

void SumIntArray2(int array[], int length, int *sum) {
  *sum = 0;
  for (int i = 0; i < length; ++i) {
    *sum += array[i];
  }
}

__int128 TestBigValue() {
  return 0;
}

typedef struct {
  char *name;
  int gender;
  int age;
  char *school_name;
} Student;

Student TestStruct() {
  Student student = {"yinlei", 1, 23, "xxx"};
  return student;
}

/**
 * 指针的参数作为返回值
 * 1. 避免函数返回值带来的开销
 * 2. 实现函数的多个返回值的目的
 *
 * 建议多hack一下汇编
 * @return
 */
int main(void) {
  int array[] = {0,1,2,3,4};
  int sum = SumIntArray(array, 5);
  int sum2;
  SumIntArray2(array, 5, &sum2);
  PRINT_INT(sum);
  PRINT_INT(sum2);

  Student student = TestStruct();
  return 0;
}
