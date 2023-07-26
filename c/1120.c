#include <stdio.h>
#include <string.h>

int main() {
  int a_len, b_len, min, count;
  char A[51];
  char B[51];
  scanf("%s %s", A, B);
  a_len = strlen(A);
  b_len = strlen(B);
  for(int i=0; i<=b_len-a_len; i++) {
    count = 0;
    for(int j=0; j<a_len; j++) {
      if(A[j]!=B[i+j]) {
        count++;
      }
    }
    if(i==0 || min>count) {
      min = count;
    }
  }
  printf("%d\n", min);
  return 0;
}