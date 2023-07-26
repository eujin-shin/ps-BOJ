#include <iostream>
using namespace std;

int num[10] = {0, };
int list[10] = {0, };

void Print(int m) {
  for(int i=0; i<m; i++) {
    printf("%d", list[i]);
    if(i==m-1) {
      printf("\n");
    } else {
      printf(" ");
    }
  }
}

void BackTrack(int n, int r, int m) {
  if(r==m) {
    Print(m);
  } else {
    for(int i=0; i<n; i++) {
      if(num[i]==0) {
        num[i] = 1;
        list[r] = i+1;
        BackTrack(n, r+1, m);
        num[i] = 0;
      }
    }
  }
}

int main() {
  int n, m;
  cin>>n>>m;
  BackTrack(n, 0, m);
  return 0;
}