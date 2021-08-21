#include <stdio.h>
#include <stdlib.h>
#include "io_utils.h"

#define PLAYER_COUNT 10

void InitPointer(int **ptr, int length, int default_value) {
  *ptr = malloc(sizeof(int) * length);
  for (int i = 0; i < length; ++i) {
    (*ptr)[i] = default_value;
  }
}

/**
 * 动态内存分配
 *
 * 常见的指针使用错误
 * 1. 忘记在使用完毕后释放内存
 * 2. 使用了已经释放的内存
 * 3. 使用了超出边界的内存
 * 4. 改变内存的指针，导致无法正常释放
 *
 * 动态内存使用建议：
 * 1. 避免修改指向已分配的内存的指针
 * 2. 对于free之后的指针主动置为NULL
 * 3. 避免将过多的指针指向动态分配的内存
 * 4. 动态内存遵从谁分配谁释放的原则
 *
 * @return
 */
int main(void) {
//  int * players = malloc(sizeof(int) * PLAYER_COUNT);

  int *players;
//  InitPointer(&players, PLAYER_COUNT, 0);
  players = calloc(PLAYER_COUNT, sizeof(int));

  for (int i = 0; i < PLAYER_COUNT; ++i) {
    PRINT_INT(players[i]);
    players[i] = i;
  }
  PRINT_INT_ARRAY(players, PLAYER_COUNT);

  players = realloc(players, PLAYER_COUNT * 2 * sizeof(int));
  PRINT_INT_ARRAY(players, PLAYER_COUNT * 2);

  if(players) {

    free(players);
  } else {

  }

  return 0;
}
