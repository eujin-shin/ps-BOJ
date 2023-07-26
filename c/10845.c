#include <stdio.h>
#include <string.h>

int main() {
  int N, x, y;
  x = 0; y = 0;
  int Q[10000] = {0, };
  scanf("%d", &N);
  char order[6];
  for(int i=0; i<N; i++) {
    scanf("%s", order);
    if(!strcmp(order, "push")) {
      scanf("%d", &Q[y]);
      y++;
    } else if(!strcmp(order, "pop")) {
      if(x==y) {
        printf("-1\n");
      } else {
        printf("%d\n", Q[x]);
        x++;
      }
    } else if(!strcmp(order, "size")) {
      printf("%d\n", y-x);
    } else if(!strcmp(order, "empty")) {
      if(x==y) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if(!strcmp(order, "front")) {
      if(x==y) {
        printf("-1\n");
      } else {
        printf("%d\n", Q[x]);
      }
    } else if(!strcmp(order, "back")) {
      if(x==y) {
        printf("-1\n");
      } else {
        printf("%d\n", Q[y-1]);
      }
    }
  }
  return 0;
}