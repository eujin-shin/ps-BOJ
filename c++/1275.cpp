#include <iostream>
#define M 100001
#define T 400000
#define ll long long
using namespace std;

ll arr[M]={0, };
ll tree[T]={0, };

ll MakeTree(int node, int l, int r) {
  if(l==r) tree[node]=arr[l];
  else {
    int mid=(l+r)/2;
    tree[node]=MakeTree(node*2, l, mid)+MakeTree(node*2+1, mid+1, r);
  }
  return tree[node];
}

ll Change(int l, int r, int a, int node) {
  if(l==a && r==a) {
    tree[node]=arr[a];
  } else if(l<=a && a<=r) {
    int mid=(l+r)/2;
    tree[node]=Change(l, mid, a, node*2)+Change(mid+1, r, a, node*2+1);
  }
  return tree[node];
}

ll GetVal(int l, int r, int x, int y, int node) {
  if(l>y || r<x) return 0;
  else if(l>=x && r<=y) return tree[node];
  int mid=(l+r)/2;
  return GetVal(l, mid, x, y, node*2)+GetVal(mid+1, r, x, y, node*2+1);
}

void Swap(int *a, int *b) {
  int temp=*a;
  *a=*b; *b=temp;
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q, x, y, a, b;
  cin>>n>>q;
  for(int i=1; i<=n; i++) cin>>arr[i];
  MakeTree(1, 1, n);
  for(int i=0; i<q; i++) {
    cin>>x>>y>>a>>b;
    if(x>y) Swap(&x, &y);
    cout<<GetVal(1, n, x, y, 1)<<'\n';
    arr[a]=b;
    Change(1, n, a, 1);
  }
  return 0;
}