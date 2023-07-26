#include <stdio.h>
#include <math.h>

int main() {
  int T;
  scanf("%d", &T);
  int ansArr[T];
  for(int i=0; i<T; i++) {
    int ans;
    double varArr[6];
    for(int l=0; l<6; l++) {
      scanf("%lf", &varArr[l]);
    }
    double x = varArr[3] - varArr[0];
    double y = varArr[4] - varArr[1];
    double n = varArr[2] + varArr[5];
    double X = x*x; double Y = y*y;
    double dis = sqrt(X+Y);
    if(varArr[2]==varArr[5]) {
      if(dis==0) {
        ans = -1;
      } else if(dis==varArr[2]+varArr[5]) {
        ans = 1;
      } else if(dis<varArr[2]+varArr[5]) {
        ans = 2;
      } else {
        ans = 0;
      }
    } else if(dis==0) {
      ans = 0;
    } else {
      double n1, n2;
      if(varArr[2]>varArr[5]) {
        n1 = varArr[2];
        n2 = varArr[5];
      } else {
        n1 = varArr[5];
        n2 = varArr[2];
      }
      if(dis<n1-n2 || dis>n1+n2) {
        ans = 0;
      } else if(dis==n1-n2 || dis==n1+n2) {
        ans = 1;
      } else{
        ans = 2;
      } 
    }
    ansArr[i] = ans;
  }
  for(int i=0; i<T; i++) {
    printf("%d\n", ansArr[i]);
  }
  return 0;
}