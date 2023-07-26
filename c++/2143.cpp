#include <iostream>
#include <vector>
#include <algorithm>
#define M 1000001
using namespace std;

int a[1000]={0, }, b[1000]={0, }, arr[M]={0, };
vector <int> v;

int bsearch(int a, int b, int k) {
  int mid, l=a, r=b;
  while(l<=r) {
    mid=(l+r)/2;
    if(v[mid]==k) return arr[mid]+1;
    else if(v[mid]<k) l=mid+1;
    else r=mid-1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, t, k, x, ans=0;
  cin>>t;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>a[i]; if(i>0) a[i]+=a[i-1];
  }
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>b[i]; if(i>0) b[i]+=b[i-1];
    v.push_back(b[i]);
    for(int j=0; j<i; j++) {
      v.push_back(b[i]-b[j]);
    }
  }
  sort(v.begin(), v.end());
  k=0;
  for(int i=1; i<v.size(); i++) {
    if(v[k]!=v[i]) k=i;
    else {
      arr[k]+=1; v.erase(v.begin()+i); i--;
    }
  }
  for(int i=0; i<n; i++) {
    for(int j=0; j<=i; j++) {
      k=a[i]-a[j];
      if(i==j) k=a[i];
      ans+=bsearch(0, v.size()-1, t-k);
    }
  }
  cout<<ans<<'\n';
  return 0;
}