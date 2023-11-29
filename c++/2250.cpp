#include <iostream>
using namespace std;

int width[10001][2]={0, }, tree[10001][2]={0, }, parent[10001]={0, };
int x=0, l=1;

void Traverse(int k, int d) {
  if(l<d) l=d;
  if(tree[k][0]>0) Traverse(tree[k][0], d+1);
  x++;
  if(width[d][0]==0 || width[d][0]>x) width[d][0]=x;
  if(width[d][1]<x) width[d][1]=x;
  if(tree[k][1]>0) Traverse(tree[k][1], d+1);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, r, ans, max=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>k>>tree[k][0]>>tree[k][1];
    parent[tree[k][0]]++;
    parent[tree[k][1]]++;
  }
  for(int i=1; i<=n; i++) {
    if(parent[i]==0) {
      r=i; break;
    }
  }
  Traverse(r, 1);
  for(int i=1; i<=l; i++) {
    if(width[i][1]-width[i][0]+1>max) {
      max=width[i][1]-width[i][0]+1;
      ans=i;
    }
  }
  cout<<ans<<' '<<max<<'\n';
  return 0;
}