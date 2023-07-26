#include <stdio.h>
#include <string.h>

int main() {
  char input_s[51];
  scanf("%s", input_s);
  int n, c;
  n = strlen(input_s);
  for(int i=0; i<n; i++) {
    c = 1;
    for(int j=0; j<n-i; j++) {
      if(input_s[i+j]!=input_s[n-1-j]) {
        c = 0;
        break;
      }
    }
    if(c || i==n-1) {
      printf("%d\n", n+i);
      break;
    }
  }
  return 0;
}