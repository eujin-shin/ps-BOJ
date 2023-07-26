#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

void LowerBound(int k) {
  int mid, l=0, r=v.size()-1, idx=0;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[mid]<k) {
      l=mid+1;
    } else {
      r=mid-1; idx=mid;
    }
  }
  v[idx]=k;
  return;
}

int main() {
  int n, tmp;
  while(cin>>n) {
    v=vector<int>();
    for(int i=0; i<n; i++) {
      cin>>tmp;
      if(v.empty() || v[v.size()-1]<tmp) v.push_back(tmp);
      else LowerBound(tmp);
    }
    cout<<v.size()<<'\n';
  }
  return 0;
}