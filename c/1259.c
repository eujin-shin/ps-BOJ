#include <stdio.h>
#include <math.h>

int main() {
  int N, count, temp, ind, revN, x;
  scanf("%d", &N);
  while(N!=0) {
    int NArr[7] = {0, };
    temp = N;
    count = 0;
    while(temp>0) {
      NArr[count] = temp%10;
      temp/=10;
      count+=1;
    }
    ind = 0;
    revN = 0;
    for(int i=count-1; i>=0; i--) {
      x = (int) pow(10.0, (double)i);
      revN += NArr[ind] * x;
      ind += 1;
    }
    if(revN == N) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
    scanf("%d", &N);
  }
  return 0;
}