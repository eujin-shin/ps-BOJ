#include <stdio.h>

int main() {
  int Arr[10];
  int RemainArr[42];
  for(int i=0; i<10; i++) {
    scanf("%d", &Arr[i]);
  }
  for(int i=0; i<42; i++) {
    RemainArr[i] = 0;
  }
  for(int i=0; i<10; i++) {
    int a = Arr[i]%42;
    RemainArr[a]=1;
  }
  int result=0;
  for(int i=0; i<42; i++) {
    if(RemainArr[i]==1) {
      result++;
    }
  }
  printf("%d\n", result);
}