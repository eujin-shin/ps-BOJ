#include <iostream>
#include <vector>
#define M 100000
using namespace std;

int in[M]={0, }, post[M]={0, };
vector <int> pre;

void GetPre(int x, int y, int p) {
  if(y<x) return;
  int root=post[p+y-x], index=in[root];
  pre.push_back(root);
  if(x==y) return;
  GetPre(x, index-1, p);
  GetPre(index+1, y, p+(index-x));
  return;
}


int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k;
    in[k]=i;
  }
  for(int i=0; i<n; i++) cin>>post[i];
  GetPre(0, n-1, 0);
  for(int i=0; i<n; i++) {
    cout<<pre[i];
    if(i==n-1) cout<<'\n';
    else cout<<' ';
  }
  return 0;
}