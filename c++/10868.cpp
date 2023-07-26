#include <iostream>
#define T 400000
#define M 100000
using namespace std;

#define min(x, y) (((x)<(y)) ? (x) : (y))

int arr[M]={0, };
int stree[T]={0, };

int MakeTree(int start, int end, int node) {
  int mid=(start+end)/2, left, right;
  if(start==end) {
    stree[node]=arr[end];
  } else {
    left = MakeTree(start, mid, node*2);
    right = MakeTree(mid+1, end, node*2+1);
    stree[node]=min(left, right);
  }
  return stree[node];
}

int GetMin(int start, int end, int l, int r, int node) {
  int mid=(start+end)/2, left, right;
  if(start>r || end<l) return 1000000000;
  if(start>=l && end<=r) return stree[node];
  left = GetMin(start, mid, l, r, node*2);
  right = GetMin(mid+1, end, l, r, node*2+1);
  return min(left, right);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, l, r;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  MakeTree(0, n-1, 1);
  for(int i=0; i<m; i++) {
    cin>>l>>r;
    cout<<GetMin(0, n-1, l-1, r-1, 1)<<'\n';
  }
  return 0;
}