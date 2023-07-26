#include <stdio.h>
#include <stdlib.h>

int Cmp(const void *a, const void *b) {
  int x = *(int *)a, y = *(int *)b;
  int ret;
  if(x>y) {
    ret = 1;
  } else if(x<y) {
    ret = -1;
  } else {
    ret = 0;
  }
  return ret;
}

void Swap(int* x, int* y) {
  int temp = *x;
  *x = *y;
  *y = temp;
}

int BinSearch(int num[], int n, int key) {
  int left = 0, right = n-1, x; 
  do {
    x = (left+right)/2;
    if(num[x]==key) {
      return 1;
    } else if(num[x]>key) {
      right = x-1;
    } else {
      left = x+1;
    }
  } while (right>=left);
  return 0;
}

int main() {
  int num[100001] = {0, };
  int ans[100001] = {0, };
  int n, m, x;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &num[i]);
  }
  qsort(num, n, sizeof(int), Cmp);
  scanf("%d", &m);
  for(int i=0; i<m; i++) {
    scanf("%d", &x);
    ans[i] = BinSearch(num, n, x);
  }
  for(int i=0; i<m; i++) {
    printf("%d\n", ans[i]);
  }
  return 0;
}