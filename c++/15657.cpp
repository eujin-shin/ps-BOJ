#include <iostream>
using namespace std;

int output[8] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

void BackTrack(int num[], int n, int m, int r, int x) {
  if(r==m) {
    for(int i=0; i<r; i++) {
      cout<<output[i];
      if(i==r-1) {
        cout<<'\n';
      } else {
        cout<<' ';
      }
    }
  } else {
    for(int i=x; i<n; i++) {
      output[r] = num[i];
      BackTrack(num, n, m, r+1, i);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int input[8] = {0, };
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>input[i];
  }
  qsort(input, n, sizeof(int), Cmp);
  BackTrack(input, n, m, 0, 0);
  return 0;
}