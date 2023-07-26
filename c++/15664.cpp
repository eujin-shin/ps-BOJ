#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> arr;
int ans[8]={0, };

void Btrack(int r, int m, int n, int x) {
  if(r==m) {
    for(int i=0; i<r; i++) {
      cout<<ans[i];
      if(i==r-1) cout<<'\n';
      else cout<<' ';
    }
  } else {
    for(int i=x; i<n; i++) {
      if(i>x && arr[i]==arr[i-1]) continue;
      ans[r]=arr[i];
      Btrack(r+1, m, n, i+1);
    }
  }
}

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  int n, m, x;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>x;
    arr.push_back(x);
  }
  sort(arr.begin(), arr.end());
  Btrack(0, m, arr.size(), 0);
  return 0;
}