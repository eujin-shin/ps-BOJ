#include <iostream>
#define T 400000
#define M 100000
#define Max 1000000000
using namespace std;

#define Min(x, y) (((x)<(y)) ? (x):(y))

int arr[M]={0, };
int stree[T]={0, };

int init(int x, int y, int node) {
  int mid=(x+y)/2, l, r;
  if(x==y) stree[node]=arr[x];
  else {
    l=init(x, mid, node*2);
    r=init(mid+1, y, node*2+1);
    stree[node]=Min(l, r);
  }
  return stree[node];
}

int revalue(int x, int y, int i, int node) {
  int mid=(x+y)/2, l, r;
  if(i<x || i>y) return stree[node];
  else if(x==y) {
    stree[node]=arr[i];
  } else {
    l=revalue(x, mid, i, node*2);
    r=revalue(mid+1, y, i, node*2+1);
    stree[node]=Min(l, r);
  }
  return stree[node];
}

int getMin(int x, int y, int a, int b, int node) {
  int mid=(x+y)/2, l, r;
  if(x>b || y<a) return Max;
  else if(x>=a && y<=b) return stree[node];
  else {
    l=getMin(x, mid, a, b, node*2);
    r=getMin(mid+1, y, a, b, node*2+1);
    return Min(l, r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q, a, b;
  cin>>n;
  for(int i=0; i<n; i++) cin>>arr[i];
  init(0, n-1, 1);
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>q>>a>>b;
    if(q==1) {
      arr[a-1]=b;
      revalue(0, n-1, a-1, 1);
    } else if(q==2) {
      cout<<getMin(0, n-1, a-1, b-1, 1)<<'\n';
    }
  }
  return 0;
}