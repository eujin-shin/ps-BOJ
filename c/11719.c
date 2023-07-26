#include <stdio.h>

int main() {
  char str[101];
  while(1) {
    gets(str);
    if (gets(str)==NULL) break;
    printf("%s\n", str);
  }
  return 0;
}