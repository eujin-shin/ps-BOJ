#include <iostream>
using namespace std;

int out_arr[8] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

void BackTrack(int num[], int n, int m, int r) {
  if(r==m) {
    for(int i=0; i<r; i++) {
      cout<<out_arr[i];
      if(i==r-1) {
        cout<<'\n';
      } else {
        cout<<' ';
      }
    }
  } else {
    for(int i=0; i<n; i++) {
      if(num[i]) {
        out_arr[r]=num[i];
        num[i] = 0;
        BackTrack(num, n, m, r+1);
        num[i] = out_arr[r];
      }
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int in_arr[8];
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>in_arr[i];
  }
  qsort(in_arr, n, sizeof(int), Cmp);
  BackTrack(in_arr, n, m, 0);
  return 0;
}