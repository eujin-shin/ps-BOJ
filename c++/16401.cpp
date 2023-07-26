#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int Check(int x, int m) {
  int c=0;
  for(int i=0; i<v.size(); i++) {
    if(v[i]<x) break;
    c+=v[i]/x;
  }
  if(m<=c) return 1;
  return 0; 
}

int Bound(int m) {
  int len=0, l=0, r=v[0], mid;
  while(l<=r) {
    mid=(l+r+1)/2;
    if(mid==0) break;
    if(Check(mid, m)) {
      len=mid; l=mid+1;
    } else r=mid-1;
  }
  return len;
}

int main() {
  ios_base::sync_with_stdio(false);
  int m, n, tmp;
  cin>>m>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  sort(v.rbegin(), v.rend());
  cout<<Bound(m)<<'\n';
  return 0;
}