#include <stdio.h>

int plus_set[4000] = {0, };
int minus_set[4000] = {0, };

int GetMid(int N, int max, int min) {
  int num, mid;
  num = min-1;
  while(N>0) {
    num++;
    if(num<0) {
      N -= minus_set[-num];
    } else {
      N -= plus_set[num];
    }
  }
  return num;
}

int GetMode(int count_max, int max, int min) {
  int num, k, mode;
  num = min;
  k = 2;
  while(k) {
    if(num<0) {
      if(minus_set[-num]==count_max) {
        mode = num;
        k--;
      }
    } else {
      if(plus_set[num]==count_max) {
        mode = num;
        k--;
      }
    }
    num++;
    if(num>max) {
      break;
    }
  }
  return mode;
}

int main() {
  int N, x, min, max, count_max, count;
  double sum, avg;
  count_max = 1;
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    scanf("%d", &x);
    sum += (double)x;
    if(i==0) {
      min = x;
      max = x;
    } else if(min>x) {
      min = x;
    } else if(max<x) {
      max = x;
    }
    if(x<0) {
      x = -x;
      minus_set[x] = minus_set[x] + 1;
      count = minus_set[x];
    } else {
      plus_set[x] = plus_set[x] + 1;
      count = plus_set[x];
    }
    if(count>count_max) {
      count_max = count;
    }
  }
  avg = sum / (double)N;
  // if(avg>=-0.5 && avg<=0) avg = 0;
  printf("%.0f\n%d\n%d\n%d\n", avg, GetMid(N/2+1, max, min), GetMode(count_max, max, min), max-min);
  return 0;
}