#include <iostream>
#define T 400000
#define M 100000
using namespace std;

#define max(x, y)	(((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))

int large[T]={0, };
int small[T]={0, };
int arr[M]={0, };

pair<int,int> MakeT(int start, int end, int node) {
  int mid=(start+end)/2;
  pair<int, int> left, right;
  if(start==end) {
    large[node]=arr[end];
    small[node]=arr[end];
  } else {
    left = MakeT(start, mid, node*2);
    right = MakeT(mid+1, end, node*2+1);
    large[node]=max(left.first, right.first);
    small[node]=min(left.second, right.second);
  }
  return make_pair(large[node], small[node]);
}

pair<int, int> Find(int start, int end, int l, int r, int node) {
  int mid=(start+end)/2;
  pair<int, int> left, right;
  if(start>=l && end<=r) return make_pair(large[node], small[node]);
  if(start>r || end<l) return make_pair(0, 1000000000);
  left = Find(start, mid, l, r, node*2);
  right = Find(mid+1, end, l, r, node*2+1);
  return make_pair(max(left.first, right.first), min(left.second, right.second));
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  MakeT(0, n-1, 1);
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    cout<<Find(0, n-1, a-1, b-1, 1).second<<' '<<Find(0, n-1, a-1, b-1, 1).first<<'\n';
  }
  return 0;
}