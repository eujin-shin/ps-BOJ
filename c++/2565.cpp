#include <iostream>
#include <vector>
using namespace std;

vector <int> v;
int arr[501]={0, };

int Bsearch(int k) {
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
  int n, a, b, idx, m=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a>>b;
    arr[a]=b;
    if(m<a) m=a;
  }
  for(int i=1; i<=m; i++) {
    if(arr[i]==0) continue;
    if(v.empty() || v[v.size()-1]<arr[i]) v.push_back(arr[i]);
    idx=Bsearch(arr[i]);
    v[idx]=arr[i];
  }
  cout<<n-v.size()<<'\n';
  return 0;
}