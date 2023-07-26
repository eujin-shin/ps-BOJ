#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector <int> v;
  int n, tmp, l, r;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>tmp; v.push_back(tmp);
  }
  l=n-2;
  while(v[l]>v[l+1] && l>=0) l--;
  if(l==-1) {
    cout<<"-1\n"; return 0;
  }
  r=n-1;
  while(v[r]<v[l]) r--;
  tmp=v[r]; v[r]=v[l]; v[l]=tmp;
  sort(v.begin()+l+1, v.end());
  for(int i=0; i<n; i++) {
    cout<<v[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}