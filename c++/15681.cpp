#include <iostream>
#include <vector>
#define N 100001
using namespace std;

vector <int> v[N];
int sub[N]={0, };

int init(int node) {
  if(sub[node]!=0) return sub[node];
  sub[node]=1;
  int next;
  for(int i=0; i<v[node].size(); i++) {
    next=v[node][i];
    if(sub[next]!=0) continue;
    sub[node]+=init(next);
  }
  return sub[node];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r, q, a, b;
  cin>>n>>r>>q;
  for(int i=0; i<n-1; i++) {
    cin>>a>>b;
    v[a].push_back(b); v[b].push_back(a);
  }
  init(r);
  for(int i=0; i<q; i++) {
    cin>>a;
    cout<<init(a)<<'\n';
  }
  return 0;
}