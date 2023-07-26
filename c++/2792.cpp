#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;
int n;

int check(int key) {
  int cnt=0;
  for(int i=0; i<v.size(); i++) {
    cnt+=v[i]/key;
    if(v[i]%key!=0) cnt++;
    if(cnt>n) break;
  }
  if(cnt>n) return -1;
  return 1;
}

int bound(int max) {
  int l=1, r=max, mid, ans;
  while(l<=r) {
    mid=(l+r)/2;
    if(check(mid)==1) {
      ans=mid; r=mid-1;
    } else {
      l=mid+1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int m, k, max=0;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>k; v.push_back(k);
    if(max<k) max=k;
  }
  cout<<bound(max)<<'\n';
  return 0;
}