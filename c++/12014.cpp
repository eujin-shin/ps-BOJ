#include <iostream>
#include <vector>
using namespace std;

int biSearch(vector <int> v, int x) {
  int mid, l=0, r=v.size()-1, ans;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[mid]<x) {
      ans=mid; l=mid+1;
    } else {
      r=mid-1;
    }
  }
  return ans;
}

int getLIS(int n) {
  vector <int> v, b;
  int x;
  for(int i=0; i<n; i++) {
    cin>>x;
    if(v.empty() || v[v.size()-1]<x) v.push_back(x);
    else if(v[0]>=x) v[0]=x;
    else v[biSearch(v, x)+1]=x; 
  }
  return v.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, k;
  cin>>t;
  for(int i=1; i<=t; i++) {
    cin>>n>>k;
    cout<<"Case #"<<i<<'\n';
    if(getLIS(n)>=k) cout<<"1\n";
    else cout<<"0\n";
  }
  return 0;
}