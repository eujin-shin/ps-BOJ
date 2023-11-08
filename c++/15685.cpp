#include <iostream>
#include <vector>
#define pnt pair<int, int>
using namespace std;

vector <pnt> v;
int map[101][101]={0, };
int dir[2][4]={{1, 0, -1, 0}, {0, -1, 0, 1}};

void Curve(int x, int y, int d, int g) {
  int t;
  v=vector<pnt>();
  map[y][x]=1;
  v.push_back(make_pair(x, y));
  map[y+dir[1][d]][x+dir[0][d]]=1;
  v.push_back(make_pair(x+dir[0][d], y+dir[1][d]));
  for(int i=0; i<g; i++) {
    t=v.size()-1;
    for(int j=t-1; j>=0; j--) {
      x=v[t].first+(v[t].second-v[j].second);
      y=v[t].second+(v[j].first-v[t].first);
      v.push_back(make_pair(x, y));
      map[y][x]=1;
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, y, d, g, cnt=0;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>x>>y>>d>>g;
    Curve(x, y, d, g);
  }
  for(int i=0; i<100; i++) {
    for(int j=0; j<100; j++) {
      if(map[i][j]==1 && map[i+1][j]==1 && map[i][j+1]==1 && map[i+1][j+1]==1) cnt++;
    }
  }
  cout<<cnt<<'\n';
}