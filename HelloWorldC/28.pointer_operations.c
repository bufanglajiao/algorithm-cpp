#include <stdio.h>
#include "io_utils.h"


/**
 * 指针的运算
 * @return
 */
int main(void) {
  {
    int a = 2;
    int *p = &a;

    PRINT_INT(p + 1);
    PRINT_INT(p);
    PRINT_INT(sizeof(int));
  }
  {
    double a = 2;
    double *p = &a;

    PRINT_INT(p + 1);
    PRINT_INT(p);
    PRINT_INT(sizeof(double));
  }
  {
    double a = 2;
    double *p = &a;
    double **pp = &p;

    PRINT_INT(pp + 1);
    PRINT_INT(pp);
    PRINT_INT(sizeof(double *));
  }

  {
    int array[] = {0,1,2,3,4};
    int *p = array;
    PRINT_INT(*(p+3));
    PRINT_INT(*(array + 3));
    PRINT_INT(*(3 + array));
    PRINT_INT(3[array]);
    PRINT_INT(array[3]);
    PRINT_INT(p[3]);

//    array = (int *)100;
    int *const array_p = array;

    PRINT_BOOL(p + 3 > p + 1);
    PRINT_BOOL(p + 3 == p + 3);

  }

  return 0;
}
