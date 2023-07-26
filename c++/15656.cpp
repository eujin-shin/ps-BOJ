#include <iostream>
using namespace std;

int in_arr[8] = {0, }, out_arr[8] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

void BackTrack(int r, int m, int n) {
  if(r==m) {
    for(int i=0; i<m; i++) {
      cout<<out_arr[i];
      if(i==m-1) {
        cout<<'\n';
      } else {
        cout<<' ';
      }
    }
  } else {
    for(int i=0; i<n; i++) {
      out_arr[r] = in_arr[i];
      BackTrack(r+1, m, n);
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>in_arr[i];
  }
  qsort(in_arr, n, sizeof(int), Cmp);
  BackTrack(0, m, n);
  return 0;
}