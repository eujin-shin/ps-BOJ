#include <stdio.h>

void PrintBlank(int n) {
  for(int i=0; i<n; i++) {
    printf(" ");
  }
}

void PrintAst(int n) {
  for(int i=0; i<n; i++) {
    printf("*");
  }
}

int main() {
  int n, count, front, mid, inside;
  scanf("%d", &n);
  front = 0; count = n*2-1; inside = n-2; mid = (n-1)*2-1;
  for(int i=1; i<=count; i++) {
    if(i==1 || i==count) {
      PrintAst(n);
      PrintBlank(mid);
      PrintAst(n);
    } else if(i==n) {
      PrintBlank(front);
      printf("*");
      PrintBlank(inside);
      printf("*");
      PrintBlank(inside);
      printf("*");
    } else {
      PrintBlank(front);
      printf("*");
      PrintBlank(inside);
      printf("*");
      PrintBlank(mid);
      printf("*");
      PrintBlank(inside);
      printf("*");
    }
    printf("\n");
    if(i<n) {
      front++;
      mid-=2;
    } else {
      front--;
      mid+=2;
    }
  }
  return 0;
}