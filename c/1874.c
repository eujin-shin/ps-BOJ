#include <stdio.h>

int main() {
  int stack[100000] = {0, };
  int answer[100000] = {0, }; // pop = 0, push = 1
  int target, x, i_s, i_a, n;
  scanf("%d", &n);
  x = 1; i_s = 0; i_a = 0;
  for(int i=0; i<n; i++) {
    scanf("%d", &target);
    if(target<x) {
      if(i_s>0 && stack[i_s-1]!=target) {
        printf("NO\n");
        return 0;
      } else {
        answer[i_a] = 0;
        i_s--;
        i_a++;
      }
    } else {
      while(x<target) {
        stack[i_s] = x;
        x++;
        i_s++;
        answer[i_a] = 1;
        i_a++;
      }
      x++;
      answer[i_a] = 1;
      i_a++;
      answer[i_a] = 0;
      i_a++;
    }
  }
  for(int i=0; i<i_a; i++) {
    if(answer[i]) {
      printf("+\n");
    } else {
      printf("-\n");
    }
  }
  return 0;
}