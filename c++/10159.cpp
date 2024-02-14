#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector <int> up[101];
vector <int> down[101];
int arr[101]={0, };

int main() {
  queue <int> dq, uq;
  int visit[101];
  int n, m, a, b, cur;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    up[b].push_back(a); down[a].push_back(b);
  }
  for(int i=1; i<=n; i++) {
    memset(visit, 0, sizeof(visit));
    visit[i]=1; arr[i]=n-1;
    for(int j=0; j<up[i].size(); j++) {
      if(visit[up[i][j]]!=0) continue;
      uq.push(up[i][j]); visit[up[i][j]]=1;
    }
    while(!uq.empty()) {
      cur=uq.front(); uq.pop();
      arr[i]-=1;
      for(int j=0; j<up[cur].size(); j++) {
        if(visit[up[cur][j]]==0) {
          visit[up[cur][j]]=1; uq.push(up[cur][j]);
        }
      }
    }
    for(int j=0; j<down[i].size(); j++) {
      if(visit[down[i][j]]!=0) continue;
      dq.push(down[i][j]); visit[down[i][j]]=1;
    }
    while(!dq.empty()) {
      cur=dq.front(); dq.pop();
      arr[i]-=1;
      for(int j=0; j<down[cur].size(); j++) {
        if(visit[down[cur][j]]==0) {
          visit[down[cur][j]]=1; dq.push(down[cur][j]);
        }
      }
    }
  }
  for(int i=1; i<=n; i++) {
    cout<<arr[i]<<'\n';
  }
  return 0;
}