#include <stdio.h>

int main() {
  char line[600] = {0, };
  int blind[5] = {0, };
  int n, m, count;
  scanf("%d %d", &m, &n);
  for(int i=0; i<m; i++) {
    *blind += n;
    for(int j=0; j<5; j++) {
      scanf("%s", line);
      if(j%5) {
        count = 0;
        for(int k=1; k<=5*n; k+=5) {
          if(line[k]=='*') {
            count++;
          }
        }
        *(blind+j) += count;
        *(blind+j-1) -= count;        
      }
    }
  }
  scanf("%s", line);
  for(int i=0; i<5; i++) {
    printf("%d", blind[i]);
    if(i!=4) {
      printf(" ");
    } else {
      printf("\n");
    }
  }
  return 0;
}