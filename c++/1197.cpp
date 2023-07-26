#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int> > vec[10001];
priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
int visit[10001]={0, };

int main() {
  int v, e, a, b, c, x, y, sum=0, min=1000000;
  cin>>v>>e;
  for(int i=0; i<e; i++) {
    cin>>a>>b>>c;
    vec[a].push_back(make_pair(c, b));
    vec[b].push_back(make_pair(c, a));
    if(min>c) {
      min=c; x=a; y=b;
    }
  }
  visit[x]=1; v-=1;
  for(int i=0; i<vec[x].size(); i++) {
    pq.push(vec[x][i]);
  }
  int cur, next;
  while(v--) {
    cur=pq.top().second; 
    if(visit[cur]==1) {
      v++; pq.pop();
      continue;
    }
    visit[cur]=1;
    sum+=pq.top().first;
    pq.pop(); 
    for(int i=0; i<vec[cur].size(); i++) {
      next=vec[cur][i].second;
      if(visit[next]==0) {
        pq.push(vec[cur][i]);
      }
    }
  }
  cout<<sum<<'\n';
  return 0;
}