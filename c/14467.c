#include <stdio.h>

int main() {
  int pos[11] = {0, };
  int n, count, num, temp;
  for(int i=1; i<=10; i++) {
    pos[i] = -1;
  }
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d %d", &num, &temp);
    if(pos[num]==-1) {
      pos[num]=temp;
    } else if(pos[num]!=temp) {
      pos[num]=temp;
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}