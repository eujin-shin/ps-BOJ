#include <iostream>
#include <string.h>
using namespace std;

int main() {
  char order[7] = {0, };
  int s[21] = {0, };
  int m, x;
  cin>>m;
  for(int i=0; i<m; i++) {
    scanf("%s", order);
    if(!strcmp(order, "add")) {
      scanf("%d", &x);
      s[x] = 1;
    } else if(!strcmp(order, "remove")) {
      scanf("%d", &x);
      s[x] = 0;
    } else if(!strcmp(order, "check")) {
      scanf("%d", &x);
      printf("%d\n", s[x]);
    } else if(!strcmp(order, "toggle")) {
      scanf("%d", &x);
      s[x] = !s[x];
    } else if(!strcmp(order, "all")) {
      for(int i=1; i<=20; i++) {
        s[i] = 1;
      }
    } else if(!strcmp(order, "empty")) {
      for(int i=1; i<=20; i++) {
        s[i] = 0;
      }
    }
  }
  return 0;
}