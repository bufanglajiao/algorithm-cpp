#include <stdio.h>
#include "io_utils.h"

void SumIntArrays(int rows, int columns, int array[][columns], int results[]) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      results[i] += array[i][j];
    }
  }
}

/**
 * 二维数组
 * 数组的数组
 * @return
 */
int main(void) {
  int vehicle_limits[5][2] = {
      0, 5,1, [1][1] = 6,2, 7,3, 8,4, 9
  };
//  int vehicle_limits[5][2] = {
//      {0, 5},
//      {1, 6},
//      {2, 7},
//      {3, 8},
//      {4, 9}
//  };
  
  // int[2]
//  vehicle_limits[0]

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 2; ++j) {
      vehicle_limits[i][j] = i + j;
    }
  }

  int scores[5][4] = {
      {135, 135, 138, 277},
      {113, 135, 138, 265},
      {113, 135, 138, 265},
      {123, 99, 140, 232},
      {98, 118, 127, 242}
  };
  int result[5] = {0};
  SumIntArrays(5, 4, scores, result);
  PRINT_INT_ARRAY(result, 5);

  return 0;
}
