#include <stdio.h>
#include <string.h>

int main() {
  int before, count, n;
  char string[1000001];
  scanf("%s", string);
  count = 0;
  n = strlen(string);
  for(int i=0; i<n; i++) {
    if(string[i]!=string[i+1]) {
      count++;
    }
  }
  printf("%d\n", count/2);
  return 0;
}