#include <stdio.h>

int main() {
  int N;
  int sizeArr[3][52]={0, };
  scanf("%d", &N);
  int ansArr[N];

  for(int i=0; i<N; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    sizeArr[0][i]=x;
    sizeArr[1][i]=y;
  }
  for(int i=0; i<N; i++) {
    int weight=sizeArr[0][i];
    int height=sizeArr[1][i];
    ansArr[i]=1;
    for(int k=0; k<N; k++) {
      if(sizeArr[0][k]>weight && sizeArr[1][k]>height) {
        ansArr[i]+=1;
      }
    }
  }
  for(int i=0; i<N; i++) {
    printf("%d", ansArr[i]);
    if(i<N-1) {
      printf(" ");
    }
    else {
      printf("\n");
    }
  }
  return 0;
}