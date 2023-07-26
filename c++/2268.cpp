#include <iostream>
#define ll long long
#define M 1000001
#define T 4000004
using namespace std;

ll st[T];
int arr[M]={0, };

ll GetSum(int a, int b, int l, int r, int node) {
  if(a>r || b<l) return 0;
  if(a<=l && b>=r) return st[node];
  int mid=(l+r)/2;
  return GetSum(a, b, l, mid, node*2)+GetSum(a, b, mid+1, r, node*2+1);
}

ll Modify(int i, int v, int l, int r, int node) {
  if(i==l && i==r) st[node]=v;
  else if(l<=i && i<=r) {
    int mid=(l+r)/2;
    st[node]=Modify(i, v, l, mid, node*2)+Modify(i, v, mid+1, r, node*2+1);
  }
  return st[node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, o, a, b, tmp;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>o>>a>>b;
    if(o==0 && a>b) {
      tmp=a; a=b; b=tmp;
    }
    if(o==0) cout<<GetSum(a, b, 1, n, 1)<<'\n';
    else Modify(a, b, 1, n, 1);
  }
  return 0;
}