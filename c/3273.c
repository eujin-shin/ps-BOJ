#include <stdio.h>

int main() {
  int num_arr[2000001] = {0, };
  int n, x, k, i, max, min, count;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &k);
    if(!i || min > k) {
      min = k;
    }
    *(num_arr+k)=1;
  }
  scanf("%d", &n);
  count = 0;
  k = n/2;
  while(1) {
    if(num_arr[k] || k==1) {
      max = k;
      break;
    }
    k--;
  }
  for(int i=k; i>0; i--) {
    if(num_arr[i] && n-i>k && num_arr[n-i]) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}