#include <stdio.h>

int main() {
  int N;
  scanf("%d", &N);
  int count = 0;
  int x = N;
  while(x>0) {
    x/=10;
    count+=1;
  }
  int numArr[count];
  while(N>0) {
    numArr[x]=N%10;
    N/=10;
    x+=1;
  }
  for(int i=count-1; i>0; i--) {
    for(int j=0; j<i; j++) {
      if(numArr[j]<numArr[j+1]) {
      int temp = numArr[j];
      numArr[j] = numArr[j+1];
      numArr[j+1] = temp;
      }
    }
  }
  for(int i=0; i<count; i++) {
    printf("%d", numArr[i]);
  }
  printf("\n");
  return 0;
}