#include <stdio.h>

/**
 * ����
 * @return
 */
#define COLOR_RED 0xFF0000
#define COLOR_GREEN 0x00FF00
#define COLOR_BLUE 0x0000FF
int main() {
  // const <type> readonly variable
  const int kRed = 0xFF0000;
  const int kGreen = 0x00FF00;
  const int kBlue = 0x0000FF;

//  kRed = 12;
  int *p_k_red = &kRed;
  *p_k_red = 0;
  printf("kRed: %d\n", kRed);

  // macro
  printf("COLOR_RED: %d\n", COLOR_RED);
//  COLOR_RED = 22;
#undef COLOR_RED
//  printf("COLOR_RED: %d\n", COLOR_RED);

  // ������ literal
  3;
  3u;
  3l;
  3.f;
  3.9;
  'c';
  "cs";
  L'��';
  L"�й�";

  // ��ҪӲ���� hard code�����Բ��ú�
  return 0;
}
