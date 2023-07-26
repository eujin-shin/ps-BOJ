#include <iostream>
using namespace std;

int arr[8] = {0, };
int output[8] = {0, };

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

void BackTrack(int n, int m, int r, int x) {
  if(m==r) {
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
      output[r] = arr[i];
      BackTrack(n, m, r+1, i+1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  qsort(arr, n, sizeof(int), Cmp);
  BackTrack(n, m, 0, 0);
  return 0;
}