#include <stdio.h>

int main() {
  int n, x, max, count;
  max = 0;
  scanf("%d", &n);
  int num_arr[10000] = {n, };
  int max_arr[10000] = {0, };
  if(n%2) {
    n++;
  }
  for(int x=n/2; x<=n; x++) {
    count = 1;
    num_arr[count] = x;
    while(num_arr[count]>=0) {
      count++;
      num_arr[count] = num_arr[count-2] - num_arr[count-1];
    }
    if(max<count) {
      max = count;
      for(int i=0; i<count; i++) {
        max_arr[i] = num_arr[i];
      }
    }
  }
  printf("%d\n", max);
  for(int i=0; i<max; i++) {
    printf("%d", max_arr[i]);
    if(i==max-1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}