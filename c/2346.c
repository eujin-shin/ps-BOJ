#include <stdio.h>

int main() {
  int n, index = 1, move;
  int balloons[1001] = {0, };
  int ans[1000] = {0, };
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &balloons[i]);
  }
  for(int i=0; i<n; i++) {
    move = balloons[index];
    balloons[index] = 0;
    ans[i] = index;
    if(i==n-1) {
      break;
    }
    if(move<0) {
      while(move!=0) {
        index--;
        if(index<1) {
          index = n;
        }
        if(balloons[index]) {
          move++;
        } 
      }
    } else {
      while(move!=0) {
        index++;
        if(index>n) {
          index = 1;
        }
        if(balloons[index]) {
          move--;
        }
      }
    }
  }
  for(int i=0; i<n; i++) {
    printf("%d", ans[i]);
    if(i==n-1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
  return 0;
}