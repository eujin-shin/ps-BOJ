#include <stdio.h>

int main() {
  int T;
  scanf("%d", &T);
  for(int i=0; i<T; i++) {
    int r;
    char str[22];
    scanf("%d %s", &r, str);
    int n = 0;
    do {
      for(int j=0; j<r; j++) {
        printf("%s", str[n]);
      }
      n ++;
    } while(str[n]!='\0');
    printf("\n");
  }
  return 0;
}