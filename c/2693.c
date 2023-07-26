#include <stdio.h>

int third(int arr[], int max) {
  int x = 3;
  while(x>0) {
    x -= arr[max];
    max--;
  }
  return max+1;
}

int main() {
  int n, max, k;
  scanf("%d", &n);
  int ans[1000] = {0, };
  for(int i=0; i<n; i++) {
    int arr[1001] = {0, };
    max = 0;
      for(int j=0; j<10; j++) {
        scanf("%d", &k);
        arr[k] = arr[k] + 1;
        if(k>max) {
          max = k;
        }
      }
    ans[i] = third(arr, max);
  }
  for(int i=0; i<n; i++) {
    printf("%d\n", ans[i]);
  } 
  return 0;
}