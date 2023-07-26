#include <iostream>
#include <vector>
#include <cstring>
#define M 100001
using namespace std;

vector <pair <int, int> > outd[M];
int visit[M]={0, };

pair <int, int> DFS(int x, int max) {
  pair <int, int> temp, result;
  int d, w;
  visit[x]=1;
  result = make_pair(0, x);
  for(int i=0; i<outd[x].size(); i++) {
    d=outd[x][i].second, w=outd[x][i].first;
    if(visit[d]==1) continue;
    visit[d]=1;
    temp=DFS(d, max);
    visit[d]=0; temp.first=temp.first+w;
    if(result.first<temp.first) result=temp;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  int v, x, d, w;
  cin>>v;
  for(int i=1; i<=v; i++) {
    cin>>x;
    while(1) {
      cin>>d;
      if(d==-1) break;
      cin>>w;
      outd[x].push_back(make_pair(w, d));
    }
  }
  x = DFS(1, 0).second;
  memset(visit, 0, M);
  cout<<DFS(x, 0).first<<'\n';
  return 0;
}