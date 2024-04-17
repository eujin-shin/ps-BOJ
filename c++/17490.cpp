#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define MAX 1000001
using namespace std;

vector <ll> v;
vector <int> c;

int main() {
  ios_base::sync_with_stdio(false);
  ll k, s, cnt=0, min;
  int n, m, a, b, tmp;
  cin>>n>>m>>k;
  for(int i=0; i<n; i++) {
    cin>>s; v.push_back(s);
  }
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    if(((a!=n || b!=1) && a>b) || (a==1 && b==n)) {
      tmp=b; b=a; a=tmp;
    }
    c.push_back(b);
  }
  if(m>1) {
    sort(c.begin(), c.end());
    c.push_back(c[0]);
    for(int i=0; i<m; i++) {
      min=MAX;
      if(c[i]>c[i+1]) {
        for(int j=1; j<c[i+1]; j++) {
          if(min>v[j-1]) min=v[j-1];
        }
        for(int j=c[i]; j<=n; j++) {
          if(min>v[j-1]) min=v[j-1];
        }
      } else {
        for(int j=c[i]; j<c[i+1]; j++) {
          if(min>v[j-1]) min=v[j-1];
        }
      }
      cnt+=min;
    }
  }
  cout<<cnt<<'\n';
  if(cnt>k) cout<<"NO\n";
  else cout<<"YES\n";
  return 0;
}