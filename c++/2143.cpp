#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> a, b, v[2];

long long Bisearch(int k) {
  int l=0, r=v[1].size()-1, mid;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[1][mid]<k) l=mid+1;
    else if(v[1][mid]>k) r=mid-1;
    else return v[0][mid];
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  long long cnt=0;
  int t, n, m, x, tmp;
  cin>>t>>n;
  for(int i=0; i<n; i++) {
    cin>>x; tmp=a.size();
    for(int j=1; j<=i; j++) a.push_back(a[tmp-j]+x);
    a.push_back(x);
  }
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>x; tmp=b.size();
    for(int j=1; j<=i; j++) b.push_back(b[tmp-j]+x);
    b.push_back(x);
  }
  sort(b.begin(), b.end());
  for(int i=0; i<b.size(); i++) {
    if(i==0 || b[i]!=b[i-1]) {
      v[1].push_back(b[i]); v[0].push_back(1);
    } else {
      v[0][v[0].size()-1]++;
    }
  }
  for(int i=0; i<a.size(); i++) {
    cnt+=Bisearch(t-a[i]);
  }
  cout<<cnt<<'\n';
  return 0;
}