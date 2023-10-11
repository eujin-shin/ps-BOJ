#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> party[50], mem[51];
queue <int> q;
int l[51]={0, }, p[50]={0, };

int main() {
  int n, m, k, x, cnt;
  cin>>n>>m>>k;
  for(int i=0; i<k; i++) {
    cin>>x; l[x]=1; q.push(x);
  }
  for(int i=0; i<m; i++) {
    cin>>k;
    for(int j=0; j<k; j++) {
      cin>>x;
      mem[x].push_back(i);
      party[i].push_back(x);
    }
  }
  cnt=m;
  while(!q.empty()) {
    x=q.front(); q.pop();
    for(int i=0; i<mem[x].size(); i++) {
      k=mem[x][i];
      if(p[k]==1) continue;
      p[k]=1; cnt--;
      for(int j=0; j<party[k].size(); j++) {
        if(l[party[k][j]]==1) continue;
        l[party[k][j]]=1;
        q.push(party[k][j]);
      }
    }
  }
  cout<<cnt<<'\n';
  return 0;
}