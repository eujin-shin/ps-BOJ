#include <iostream>
using namespace std;

int up[100001]={0, };
int p[100001]={0, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, x, w;
  cin>>n>>m;
  for(int i=1; i<=n; i++) cin>>up[i];
  for(int i=0; i<m; i++) {
    cin>>x>>w;
    p[x]+=w;
  }
  for(int i=1; i<=n; i++) {
    if(i>1) p[i]+=p[up[i]];
    cout<<p[i];
    if(i<n) cout<<' ';
  }
  cout<<'\n';
  return 0;
}