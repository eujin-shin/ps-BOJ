#include <stdio.h>

int main() {
  int arr_time[1000001] = {0, };
  int n, index, time, min, max, ans;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d %d", &index, &time);
    if(i==0) {
      min = index;
      max = index;
    } else if(min>index) {
      min = index;
    } else if(max<index) {
      max = index;
    }
    arr_time[index] = arr_time[index] + time;
  }
  ans = 0;
  for(int i=min; i<=max; i++) {
    if(arr_time[i]==0) {
      continue;
    }
    if(i>ans) {
      ans = i+arr_time[i];
    } else {
      ans += arr_time[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}