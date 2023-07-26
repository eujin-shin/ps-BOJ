#include <stdio.h>

int main() {
  // eight five four nine one seven six three two zero
  // 8 88 85 84 89 81 87 86 83 82
  // 5 58 55 54 59 51 57 ...
  int num_list[11] = {0, 8, 5, 4, 9, 1, 7, 6, 3, 2, 0};
  int num, count, m, n;
  scanf("%d %d", &m, &n);
  for(int i=1; i<10; i++) {
    for(int j=0; j<11; j++) {
      if(j==0) {
        num = num_list[i];
      } else {
        num = num_list[i]*10+num_list[j];
      }
      if(num>=m && num<=n) {
        printf("%d", num);
        count++;
        if(count==n-m+1) {
          printf("\n");
          return 0;
        } else if(count%10==0) {
          printf("\n");
        } else {
          printf(" ");
        }
      }
    }
  }
}