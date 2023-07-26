#include <stdio.h>
#include <string.h>

int main() {
  int n, x, m, count;
  char word[100001];
  char stack[100001];
  scanf("%d", &n);
  count = 0;
  for(int i=0; i<n; i++) {
    scanf("%s", word);
    count++;
    m = strlen(word);
    x = 0;
    for(int j=0; j<m; j++) {
      if(x==0) {
        stack[x] = word[j];
        x++;
      } else {
        if(stack[x-1]==word[j]) {
          x--;
        } else {
          stack[x] = word[j];
          x++;
        }
      }
    }
    if(x!=0) {
      count--;
    }
  }
  printf("%d\n", count);
  return 0;
}