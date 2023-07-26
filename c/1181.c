#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Cmp(const void *a, const void *b) {
  if(strlen(a)<strlen(b)) {
    return -1;
  } else if(strlen(a)>strlen(b)) {
    return 1;
  } else {
    int x = strcmp(a, b);
    return x;
  }
}

int main() {
  char words[20100][52];
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s", words[i]);
  }
  qsort(words, n, sizeof(words[0]), Cmp);
  for(int i=0; i<n; i++) {
    if(strcmp(words[i], words[i-1])) {
      printf("%s\n", words[i]);
    }
  }
  return 0;
}