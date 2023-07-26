#include <iostream>
#include <cstring>
#define M 5000
using namespace std;

int st[M];

int Solve(int a, int b, int l, int r, int node) {
  if(a==l && b==r) {
    if(st[node]<=r-l) {
      st[node]++; return 1;
    }
    return 0;
  } else if(a>r || b<l) return 0;
  if(st[node]>r-l) return 0;
  int mid=(l+r)/2, tmp;
  tmp=Solve(a, b, l, mid, node*2)+Solve(a, b, mid+1, r, node*2+1);
  st[node]+=tmp;
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, a, b;
  cin>>t;
  while(t--) {
    cin>>n>>m;
    memset(st, 0, sizeof(st));
    for(int i=0; i<m; i++) {
      cin>>a>>b;
      Solve(a, b, 1, n, 1);
    }
    cout<<st[1]<<'\n';
  }
  return 0;
}