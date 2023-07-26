#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p;
  int *p_ans;
  int n, l, min, count;
  scanf("%d %d", &n, &l);
  p = (int *)malloc(sizeof(int)*n);
  p_ans = (int *)malloc(sizeof(int)*n);
  for(int i=0; i<n; i++) {
    scanf("%d", (p+i));
  }
  count = 0;
  min = *p;
  for(int i=0; i<n; i++) {
    if(i<l) {
      if(min>*(p+i)) {
        min = *(p+i);
        count = 0;
      }
      *(p_ans+i) = min;
      count++;
    } else {
      if(count>=l) {
        min = *(p+i);
        for(int j=1; j<l; j++) {
          if(min>*(p+i-j)) {
            min = *(p+i-j);
            count = j;
          }
        }
      } else if(min>*(p+i)) {
        min = *(p+i);
        count = 0;
      } else if(min==*(p+i)) {
        count = 0;
      }
      *(p_ans+i) = min;
      count++;
    }
  }
  for(int i=0; i<n; i++) {
    printf("%d", *(p_ans+i));
    if(i==n-1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}
