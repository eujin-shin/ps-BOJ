#include <iostream>
#include <queue>
#include <string>
using namespace std;

int map[100][100]={0, };
queue <pair<int, int> > q;

int main() {
  int h, w, cur, cnt, l, x, y;
  string tmp;
  cin>>h>>w; cnt=0;
  for(int i=0; i<h; i++) {
    cin>>tmp;
    for(int j=0; j<w; j++) {
      if(tmp[j]!='c') continue;
      q.push(make_pair(i, j));
    }
  }
  l=1; cur=q.size(); cnt=0;
  while(!q.empty()) {
    y=q.front().first; x=q.front().second;
    q.pop();
    if(map[y][x]==0) map[y][x]=l;
    if(x<w-1) {
      q.push(make_pair(y, x+1));
      cnt++;
    }
    cur--;
    if(cur==0) {
      l++; cur=cnt; cnt=0;
    }
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cout<<map[i][j]-1;
      if(j<w-1) cout<<" ";
    }
    cout<<"\n";
  }
  return 0;
}