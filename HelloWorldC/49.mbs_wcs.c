#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <wchar.h>
#include "io_utils.h"

/**
 * 宽字符串与窄字符串的转换
 * @return
 */
int main(void) {
  {
    PRINT_BOOL(iswalpha(L'A'));
    PRINT_BOOL(iswdigit(L'2'));

    wchar_t *wcs = L"你好 Hello";
    size_t length = wcslen(wcs);
    PRINT_INT(length); // 告诉编译器我用utf8 : -DCMAKE_C_FLAGS="/utf8"

    wchar_t src[] = L"HelloWorld";
    wchar_t *dest = malloc(sizeof(wchar_t) * 11);
    wmemset(dest, 0, 11);
    wmemcpy(dest, src, 11);
    wprintf(dest);
    wmemcpy(dest + 3, dest + 1, 4);
    wprintf(dest);
    free(dest);
  }

  char *new_locale = setlocale(LC_ALL, "zh_CN.utf8");
  if(new_locale){
    puts(new_locale);
  }
  {
    char mbs[] = "你好"; //mbs存的是编译器编码后的字节
    wchar_t wcs[10];
    mbstowcs(wcs, mbs, 10);//编译器解码再转换为unicode码点, 依赖local
    wprintf(L"%s\n", wcs);
  }

  return 0;
}
