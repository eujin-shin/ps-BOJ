#include <stdio.h>

int picture[102][102] = {0, };

int main() {
  int sum, N, M, start_x, start_y, end_x, end_y;
  sum = 0;
  scanf("%d %d", &N, &M);
  for(int i=0; i<N; i++) {
    scanf("%d %d %d %d", &start_x, &start_y, &end_x, &end_y);
    for(int j=start_x; j<=end_x; j++) {
      for(int k=start_y; k<=end_y; k++) {
        if(picture[j][k]>M) {
          continue;
        } else if(picture[j][k]==M) {
          picture[j][k] += 1;
          sum ++;
        } else {
          picture[j][k] += 1;
        }
      }
    }
  }
  printf("%d\n", sum);
  return 0;
}