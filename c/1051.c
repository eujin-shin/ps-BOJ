#include <stdio.h>

int main() {
  int square[51][51] = {0, };
  int line[51] = {0, };
  int n, m, l, max, x, y, temp, k;
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++) {
    int count[10] = {0, };
    for(int j=0; j<m; j++) {
      scanf("%1d", &temp);
      line[j] = temp;
      count[temp]=count[temp]+1;
    }
    for(int j=0; j<m; j++) {
      if(count[line[j]]>1) {
        square[i][j] = line[j]+1;
      }
    }
  }
  max = 1;
  for(int i=0; i<n; i++) {
    if(i+max>=n) {
      break;
    }
    for(int j=0; j<m; j++) {
      if(square[i][j]>0) {
        k = square[i][j];
        x = j;
        for(int h=m-1; h>=x+max; h--) {
          if(square[i][h]==k) {
            y = h;
            l = y-x;
            if(square[i+l][x]==k && square[i+l][y]==k) {
              max = l+1;
            }
          }
        }
      }
    }
  }
  printf("%d\n", max*max);
  return 0;
}