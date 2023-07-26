#include <stdio.h>
#include <string.h>

int main() {
  char sub[11] = {0, };
  char main[22] = {0, };
  int n, len, flag, count=0;
  scanf("%s", sub);
  scanf("%d", &n);
  len = strlen(sub);
  for(int i=0; i<n; i++) {
    scanf("%s", main);
    for(int i=0; i<10; i++) {
      main[10+i] = main[i];
    }
    for(int k=0; k<10; k++) {
      flag = 0;
      for(int j=0; j<len; j++) {
        if(*(main+k+j)!=sub[j]) {
          break;
        }
        if(j==len-1) {
          flag = 1;
        }
      }
      if(flag) {
        count++;
        break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}