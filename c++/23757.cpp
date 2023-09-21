#include <iostream>
#include <vector>
using namespace std;

vector <int> v;

void Insert(int k) {
  int cur=v.size(), p;
  v.push_back(k);
  while(cur>0) {
    p=(cur-1)/2;
    if(v[p]>v[cur]) break;
    v[cur]=v[p]; v[p]=k;
    cur=p;
  }
  return;
}

int Pop() {
  int top=v[0], k, cur=0, l, r, tmp;
  k=v[v.size()-1];
  v[0]=k; v.pop_back();
  while(cur<v.size()) {
    tmp=cur;
    l=cur*2+1; r=cur*2+2;
    if(l<v.size() && v[l]>v[tmp]) tmp=l;
    if(r<v.size() && v[r]>v[tmp]) tmp=r;
    if(tmp==cur) break;
    v[cur]=v[tmp]; v[tmp]=k;
    cur=tmp;
  }
  return top;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, tmp, ans=1;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    cin>>x;
    Insert(x);
  }
  for(int i=0; i<m; i++) {
    cin>>x;
    tmp=Pop();
    if(tmp<x) {
      ans=0; break;
    } else if(tmp>x) {
      Insert(tmp-x);
    }
  }
  cout<<ans<<'\n';
  return 0;
}