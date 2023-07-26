#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c[10]={0, }, n, k;
vector <int> v;

void DFS(int r, int x) {
  if(r==k) {
    v.push_back(x);
    return;
  }
  int tmp;
  for(int i=0; i<n; i++) {
    if(c[i]<0) continue;
    tmp=c[i]; c[i]=-1;
    if(tmp<10) DFS(r+1, x*10+tmp);
    else DFS(r+1, x*100+tmp);
    c[i]=tmp;
  }
  return;
}

int main() {
  cin>>n>>k;
  for(int i=0; i<n; i++) cin>>c[i];
  DFS(0, 0);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  cout<<v.size()<<'\n';
  return 0;
}