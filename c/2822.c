#include <stdio.h>

int main() {
  int points[9] = {150, };
  int nums[9] = {0, };
  int min_1 = 0, min_2 = 0, min_3 = 0, sum;
  sum = 0;
  for(int i=1; i<9; i++) {
    scanf("%d", &points[i]);
    sum+=points[i];
    if(points[min_3]>points[i]) {
      nums[i] = 1;
      nums[min_3] = 0;
      if(points[min_2]<=points[i]) {
        min_3 = i;
      } else if(points[min_1]<=points[i]) {
        min_3 = min_2;
        min_2 = i;
      } else {
        min_3 = min_2;
        min_2 = min_1;
        min_1 = i;
      }
    }
  }
  sum -= (points[min_1]+points[min_2]+points[min_3]);
  printf("%d\n", sum);
  for(int i=1; i<9; i++) {
    if(!nums[i]) {
      printf("%d ", i);
    }
  }
  printf("\n");
  return 0;
}