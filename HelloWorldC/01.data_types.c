#include <stdio.h>
#include <limits.h>

/**
 * �������� ������
 * @return
 */
int main() {
  float a_float = 3.14f; // 6 +-10^-37 ~ 10^37
  printf("size of float: %d\n", sizeof(float));
  double a_double = 3.14; // 15~16
  printf("size of double: %d\n", sizeof(double));

//  12345;
//  1.2345e4;

  float lat = 39.90815f;
  int lat06 = (int)(lat * 1e6);// 39908150
  printf("%f", 39.908156f - lat);

  return 0;
}

/**
 * �������� char
 * @return
 */
/*
int main() {
  // �ַ��� ASCII
  char a = 'a'; // 97
  char char_1 = '1'; // 49
  char char_0 = '0'; // 48

  char i = 0; // NULL \0

  // \n: new line
  // \b: backspace
  // \r: return
  // \t: table
  // \': ' �ַ�������
  // \": " �ַ���������
  char char_1_escape_oct = '\61';
  char char_1_escape_hex = '\x31';
  char newline = '\n';

  printf("char a: %d\n", a);
  printf("char char_1: %d\n", char_1);
  printf("char i: %d\n", i);

  printf("char char_1: %c\n", char_1);
  printf("char char_1: %c\n", char_1_escape_oct);
  printf("char char_1: %c\n", char_1_escape_hex);

  // Unicode: CJK
  wchar_t zhong = L'��';// C95
  wchar_t zhong_hex = L'\u4E2D';// C95
  printf("��: %d\n", zhong);// code point.
  printf("��: %d\n", zhong_hex);// code point.
  // �ַ���
  char *string = "��";

  return 0;
}
*/

/**
 * �������� int
 * @return
 */
 /*
int main() {
  short int short_int = 0;
  int i = 100;
  long int long_int = 0;
  long long longlong_int = 0;

  unsigned int unsigned_int = 123;

  // d = decimal
  // x = hex
  // o = oct
  printf("int in hex: %x\n", i);
  printf("int in oct: %o\n", i);

  // %hd: short decimal
  // %d: decimal
  // %ld: long decimal
  // %lld: long long decimal
  // %hu: unsigned short decimal
  // \n: new line
  printf("short int %hd\n", short_int);
  size_t size_of_int = sizeof(int);
  printf("short int: %d\n", sizeof(short int));
  printf("int: %d\n", sizeof(int));
  printf("long int: %d\n", sizeof(long int));
  printf("long long int: %llu\n", sizeof(long long int));

  printf("max int %d, min %d\n", INT_MAX, INT_MIN);
  printf("max long int %ld, min %ld\n", LONG_MAX, LONG_MIN);
  printf("unsigned Max int %u, unsigned min %d\n", UINT_MAX, 0);
  return 0;
}
*/