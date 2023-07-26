#include <stdio.h>

int main() {
  int x, count;
  char res[5] = {'E', 'A', 'B', 'C', 'D'};
  for(int i=0; i<3; i++) {
    count=0;
    for(int k=0; k<4; k++) {
      scanf("%d", &x);
      if(x==0) {
        count++;
      }     
    }
    printf("%c\n", res[count]);
  }
  return 0;
}