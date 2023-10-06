#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#define pnt pair<int, int>
using namespace std;

vector <string> v;
queue <pnt> fire_q;
int xm[4]={0, 0, -1, 1}, ym[4]={1, -1, 0, 0};
int fire_set[1000][1000]={0, };

void Fire(int w, int h) {
  int cur_x, cur_y, next_x, next_y;
  while(!fire_q.empty()) {
    cur_x=fire_q.front().first;
    cur_y=fire_q.front().second;
    fire_q.pop();
    for(int i=0; i<4; i++) {
      next_x=cur_x+xm[i];
      next_y=cur_y+ym[i];
      if(next_x<0 || next_x>=w || next_y<0 || next_y>=h) continue;
      if(v[next_y][next_x]=='.' && fire_set[next_y][next_x]==0) {
        fire_set[next_y][next_x]=fire_set[cur_y][cur_x]+1;
        fire_q.push(make_pair(next_x, next_y));
      }
    }
  }
  return;
}

int Escape(int w, int h, int x, int y) {
  int visit[1000][1000]={0, };
  int cur_x, cur_y, next_x, next_y, tmp;
  queue <pnt> q;
  q.push(make_pair(x, y));
  visit[y][x]=1;
  int sec=1, next=1, cnt=0;
  while(!q.empty()) {
    cur_x=q.front().first;
    cur_y=q.front().second;
    q.pop();
    for(int i=0; i<4; i++) {
      next_x=cur_x+xm[i];
      next_y=cur_y+ym[i];
      if(next_x<0 || next_x>=w || next_y<0 || next_y>=h) return sec;
      tmp=fire_set[next_y][next_x];
      if(v[next_y][next_x]!='.' || visit[next_y][next_x]==1 || (tmp!=0 && tmp-1<=sec)) continue;
      visit[next_y][next_x]=1;
      q.push(make_pair(next_x, next_y));
      cnt++;
    }
    next--;
    if(next==0) {
      sec++; next=cnt; cnt=0;
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  queue <pnt> q;
  string s;
  int t, w, h, x, y, res;
  cin>>t;
  while(t--) {
    cin>>w>>h;
    v=vector<string>();
    memset(fire_set, 0, sizeof(fire_set));
    for(int i=0; i<h; i++) {
      cin>>s;
      for(int j=0; j<w; j++) {
        if(s[j]=='@') {
          x=j; y=i; s[j]='.';
        } else if(s[j]=='*') {
          fire_set[i][j]=1; 
          fire_q.push(make_pair(j, i));
        }
      }
      v.push_back(s);
    }
    Fire(w, h);
    res=Escape(w, h, x, y);
    if(res<0) cout<<"IMPOSSIBLE\n";
    else cout<<res<<"\n";
  }
  return 0;
}