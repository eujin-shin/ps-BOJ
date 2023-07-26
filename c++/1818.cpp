#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

int Bound(int k) {
  int l=0, r=v.size()-1, mid, idx;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[mid]>=k) {
      idx=mid; r=mid-1;
    } else l=mid+1;
  }
  return idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, idx;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k;
    if(v.empty() || v[v.size()-1]<k) v.push_back(k);
    else {
      idx=Bound(k); 
      v[idx]=k;
    }
  }
  cout<<n-v.size()<<'\n';
  return 0;
}