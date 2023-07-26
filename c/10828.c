#include <stdio.h>
#include <string.h>

int stack[10001] = {0, };

int main() {
  char order[6];
  int n, x, y;
  x = 0; y = 0;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%s", order);
    if(!strcmp(order, "push")) {
      scanf("%d", &stack[y]);
      y++;
    } else if(!strcmp(order, "pop")) {
      if(x==y) {
        printf("-1\n");
      } else {
        y--;
        printf("%d\n", stack[y]);
      }
    } else if(!strcmp(order, "size")) {
      printf("%d\n", y-x);
    } else if(!strcmp(order, "empty")) {
      if(x==y) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if(!strcmp(order, "top")) {
      if(x==y) {
        printf("-1\n");
      } else {
        printf("%d\n", stack[y-1]);
      }
    }
  }
  return 0;
}