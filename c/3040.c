#include <stdio.h>

int main() {
  int numArr[9];
  int ansArr[7];
  int sum = 0;
  for(int i=0; i<9; i++) {
    scanf("%d", &numArr[i]);
    sum += numArr[i];
  }
  int n = sum - 100;
  for(int i=0; i<9; i++) {
    int m = n - numArr[i];
    int exit = 0;
    for(int j=i+1; j<9; j++) {
      if(numArr[j]==m) {
        numArr[i]=0;
        numArr[j]=0;
        exit = 1;
        break;
      }
    }
    if(exit==1) {
      break;
    }
  }
  int index = 0;
  for(int i=0; i<9; i++) {
    if(numArr[i]!=0) {
      ansArr[index]=numArr[i];
      index+=1;
    }
  }
  for(int i=0; i<7; i++) {
    printf("%d\n", ansArr[i]);
  }
  return 0;
}