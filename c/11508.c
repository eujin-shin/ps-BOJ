#include <stdio.h>

int main() {
  int prices[100001] = {0, };
  int sum, n, temp, min, max, count;
  scanf("%d", &n);
  sum = 0;
  for(int i=0; i<n; i++) {
    scanf("%d", &temp);
    if(i==0) {
      min = temp;
      max = temp;
    } else if(min>temp) {
      min = temp;
    } else if(max<temp) {
      max = temp;
    }
    sum += temp;
    *(prices+temp) += 1;
  }
  count = 0;
  for(int i=max; count<=(n/3)*3; i--) {
    
  }
}