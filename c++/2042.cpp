#include <iostream>
#include <vector>
#define T 4000000
#define M 1000000
using namespace std;

long long stree[T]={0, };
long long arr[M]={0, };

long long MakeTree(int start, int end, int node) {
  int mid=(start+end)/2;
  if(start==end) stree[node]=arr[end];
  else stree[node]=MakeTree(start, mid, node*2)+MakeTree(mid+1, end, node*2+1);
  return stree[node];
}

void Update(int start, int end, int index, long long value, int node) {
  if(index<start || index>end) return;
  stree[node]-=arr[index];
  stree[node]+=value;
  int mid=(start+end)/2;
  if(start==end) return;
  Update(start, mid, index, value, node*2);
  Update(mid+1, end, index, value, node*2+1);
  return;
}

long long Sum(int start, int end, int left, int right, int node) {
  int mid=(start+end)/2;
  if(start>=left && end<=right) return stree[node];
  if(start>right || end<left) return 0;
  return Sum(start, mid, left, right, node*2)+Sum(mid+1, end, left, right, node*2+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, a, b;
  long long c;
  cin>>n>>m>>k;
  for(int i=0; i<n; i++) {
    cin>>arr[i];
  }
  stree[1] = MakeTree(0, n-1, 1);
  for(int i=0; i<m+k; i++) {
    cin>>a>>b>>c;
    if(a==1) {
      Update(0, n-1, b-1, c, 1);
      arr[b-1]=c;
    } else if(a==2) {
      cout<<Sum(0, n-1, b-1, c-1, 1)<<'\n';
    }
  }
  return 0;
}