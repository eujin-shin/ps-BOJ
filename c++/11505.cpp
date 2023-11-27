#include <iostream>
#define T 4000000
#define M 1000001
#define Mod 1000000007
#define ll long long
using namespace std;

ll st[T]={0, }, arr[M]={0, };

ll Build(int s, int e, int n) {
  if(s==e) return st[n]=arr[s];
  int mid=(s+e)/2;
  return st[n]=(Build(s, mid, n*2) * Build(mid+1, e, n*2+1)) % Mod;
}

ll Get(int s, int e, int x, int y, int n) {
  if(s>y || e<x) return 1;
  else if(s>=x && e<=y) return st[n];
  int mid=(s+e)/2;
  return (Get(s, mid, x, y, n*2) * Get(mid+1, e, x, y, n*2+1)) % Mod;
}

ll Update(int s, int e, int d, int n) {
  if(s==e && s==d) return st[n]=arr[d];
  else if(d<s || e<d) return st[n];
  int mid=(s+e)/2;
  return st[n]=(Update(s, mid, d, n*2) * Update(mid+1, e, d, n*2+1)) % Mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, o, x, y;
  cin>>n>>m>>k;
  for(int i=1; i<=n; i++) cin>>arr[i];
  Build(1, n, 1);
  for(int i=0; i<m+k; i++) {
    cin>>o>>x>>y;
    if(o==1) {
      arr[x]=y; Update(1, n, x, 1);
    } else if(o==2) {
      cout<<Get(1, n, x, y, 1)<<'\n';
    }
  }
  return 0;
}