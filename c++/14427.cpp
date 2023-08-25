#include <iostream>
using namespace std;

int arr[100001]={0, };
int st[400004]={0, };

int MakeTree(int idx, int l, int r) {
  if(l==r) {
    st[idx]=l;
  } else {
    int x, y, mid=(l+r)/2;
    x=MakeTree(idx*2, l, mid);
    y=MakeTree(idx*2+1, mid+1, r);
    st[idx]=((arr[x]>arr[y]) ? (y) : (x));
  }
  return st[idx];
}

int Update(int k, int l, int r, int idx) {
  if(k>=l && k<=r) {
    if(l==r) {
      st[idx]=k;
    } else {
      int x, y, mid=(l+r)/2;
      x=Update(k, l, mid, idx*2);
      y=Update(k, mid+1, r, idx*2+1);
      st[idx]=((arr[x]>arr[y]) ? (y) : (x));
    }
  } 
  return st[idx];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, k, v;
  cin>>n;
  for(int i=1; i<=n; i++) cin>>arr[i];
  MakeTree(1, 1, n);
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>x;
    if(x==1) {
      cin>>k>>v;
      arr[k]=v;
      Update(k, 1, n, 1);
    } else {
      cout<<st[1]<<'\n';
    }
  }
  return 0;
}