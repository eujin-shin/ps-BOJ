#include <stdio.h>

int main() {
  int h, m;
  scanf("%d %d", &h, &m);
  if(h==0 && m<45) {
    h=23;
    m=15+m;
  } else if(m<45) {
    h--;
    m=15+m;
  } else {
    m=m-45;
  }
  printf("%d %d\n", h, m);
  return 0;
}