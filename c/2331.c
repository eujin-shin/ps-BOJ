#include <stdio.h>
#include <math.h>

int GetNext(int prev, int p) {
  int next=0;
  while(prev) {
    next+=(int)pow(prev%10, (double)p);
    prev/=10;
  }
  return next;
}

int main() {
  int arr[1000000] = {0, };
  int n, p, temp, flag, index = 1;
  scanf("%d %d", &n, &p);
  arr[0] = n;
  while(1) {
    flag = 0;
    temp = GetNext(arr[index-1], p);
    for(int i=0; i<index; i++) {
      if(arr[i]==temp) {
        flag = 1;
        index = i;
        break;
      }
    }
    if(flag) {
      break;
    } else {
      arr[index] = temp;
      index++;
    }
  }
  printf("%d\n", index);
  return 0;
}