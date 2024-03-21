#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <pair<int, int> >  pos;
vector <int> dist, child, parent, cnt;
queue <int> q, t;
int map[502][502]={0, };


int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, x, y, s;
  cin>>n>>m>>k;
  for(int i=0; i<k; i++) {
    cin>>x>>y;
    pos.push_back(make_pair(x, y));
    map[y][x]=i+1;
    dist.push_back(-1); 
    child.push_back(0); 
    parent.push_back(0);
    cnt.push_back(1);
  }
  cin>>s;
  q.push(--s); dist[s]=0; parent[s]=-1;
  int cur, next, d, nx, ny, v=0;
  bool b;
  while(!q.empty()) {
    cur=q.front(); q.pop(); d=dist[cur]+1; b=true; v++;
    x=pos[cur].first; y=pos[cur].second;
    for(int i=-1; i<=1; i++) {
      for(int j=-1; j<=1; j++) {
        nx=x+i; ny=y+j; 
        if(nx<1 || ny<1 || nx>n || ny>m) continue;
        next=map[ny][nx];
        if(--next<0) continue;
        if(dist[next]>=0 && dist[next]<d) continue;
        else if(dist[next]==d && cur<parent[next]) {
          child[parent[next]]--; child[cur]++;
          if(child[parent[next]]==0) t.push(parent[next]);
          parent[next]=cur; b=false;
        } else if(dist[next]<0 || dist[next]>d) {
          dist[next]=d; parent[next]=cur; child[cur]++;
          q.push(next); b=false;
        }
      }
    }
    if(b) t.push(cur);
  }
  if(v<k) {
    cout<<"-1\n";
    return 0;
  }
  int p;
  while(!t.empty()) {
    cur=t.front(); t.pop();
    p=parent[cur];
    if(p<0) continue;
    cnt[p]+=cnt[cur];
    if(--child[p]==0) t.push(p);
  }
  for(int i=0; i<k; i++) {
    if(i>0) cout<<' ';
    cout<<cnt[i];
  }
  cout<<'\n';
  return 0;
}