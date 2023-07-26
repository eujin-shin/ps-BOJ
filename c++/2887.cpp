#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pnt pair<int, int>
#define ppnt pair<int, pnt>
using namespace std;

int map[4][100000]={0, }, n;
priority_queue <ppnt, vector<ppnt>, greater<ppnt> > pq;
vector <pnt> pos[4];

void insert(int x) {
  int idx, t, len;
  map[0][x]=1;
  for(int i=1; i<4; i++) {
    idx=map[i][x];
    if(idx>0 && map[0][pos[i][idx-1].second]==0) {
      t=pos[i][idx-1].second;
      len=pos[i][idx].first-pos[i][idx-1].first;
      pq.push(make_pair(len, make_pair(x, t)));
    } 
    if(idx<n-1 && map[0][pos[i][idx+1].second]==0) {
      t=pos[i][idx+1].second;
      len=pos[i][idx+1].first-pos[i][idx].first;
      pq.push(make_pair(len, make_pair(x, t)));
    } 
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  long long sum=0, len;
  int tmp, cnt=1, a, b;
  cin>>n;
  for(int i=0; i<n; i++) {
    for(int j=1; j<4; j++) {
      cin>>tmp; 
      pos[j].push_back(make_pair(tmp, i));
    }
  }
  sort(pos[1].begin(), pos[1].end());
  sort(pos[2].begin(), pos[2].end());
  sort(pos[3].begin(), pos[3].end());
  for(int i=0; i<n; i++) {
    for(int j=1; j<4; j++) {
      map[j][pos[j][i].second]=i;
    }
  }
  insert(0);
  while(cnt<n) {
    len=pq.top().first;
    a=pq.top().second.first;
    b=pq.top().second.second;
    pq.pop();
    if(map[0][a]==0 && map[0][b]==1) {
      insert(a); sum+=len; cnt++;
    } else if(map[0][a]==1 && map[0][b]==0) {
      insert(b); sum+=len; cnt++; 
    }
  }
  cout<<sum<<'\n';
  return 0;
}