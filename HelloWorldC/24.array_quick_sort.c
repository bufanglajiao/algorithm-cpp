#include <stdio.h>
#include "io_utils.h"
#include <stdlib.h>
#include <time.h>
#define PLAYER_COUNT 50

void SwapElements(int array[], int first, int second) {
  int temp = array[first];
  array[first] = array[second];
  array[second] = temp;
}

void ShuffleArray(int array[], int length) {
  srand(time(NULL));
  for (int i = length - 1; i > 0; --i) {
    int random_number = rand() % i;
    SwapElements(array, i, random_number);
  }
}

int Partition(int array[], int low, int high) {
  int pivot = array[high];
  int partition = low;
  for (int i = low; i < high; ++i) {
    if(array[i] < pivot) {
      SwapElements(array, i, partition++);
    }
  }
  SwapElements(array, partition, high);
  return partition;
}

void QuickSort(int array[], int low, int high) {
  if(low >= high) return;
  int partition = Partition(array, low, high);
  QuickSort(array, low, partition - 1);
  QuickSort(array, partition + 1, high);
}

/**
 * 数组元素的排序——快排
 * @return
 */
int main(void) {

  int players[PLAYER_COUNT];
  for (int i = 0; i < 50; ++i) {
    players[i] = i;
  }
  PRINT_INT_ARRAY(players, PLAYER_COUNT);
  ShuffleArray(players, PLAYER_COUNT);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  QuickSort(players, 0, PLAYER_COUNT - 1);
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  return 0;
}
