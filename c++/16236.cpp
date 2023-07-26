#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[21][21] = {0, };
int visit[21][21]={0, };
int x_move[4] = {0, -1, 1, 0};
int y_move[4] = {-1, 0, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  int n, size=2, eat=0;
  queue <pair<int, int> > q;
  pair<int, int> cur, next, move;
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>map[j][i]; 
      if(map[j][i]==9) {
        map[j][i] = 0;
        q.push(make_pair(j, i));
        visit[j][i]=1;
      } 
    }  
  }
  int now, count, level, time, x, y;
  bool find=false;
  now = level = 1; count = time = 0;
  while(!q.empty()) {
    if(now==0) {
      if(find) {
        memset(visit, 0, sizeof(visit));
        time+=level; find=false;
        now=level=1; count=0;
        map[move.first][move.second]=0;
        visit[move.first][move.second]=1;
        eat++;
        if(eat==size) {
          eat=0; size++;
        }
        q = queue <pair<int, int> >(); 
        q.push(move);
        continue;
      } else {
        now = count; level++; count = 0;
      }
    }
    cur=q.front(); q.pop();
    for(int i=0; i<4; i++) {
      x=cur.first+x_move[i];
      y=cur.second+y_move[i];
      if(x<1 || x>n || y<1 || y>n) continue; 
      if(visit[x][y]==1 || map[x][y]>size) continue;
      if(!find && map[x][y]<=size) {
        q.push(make_pair(x, y));
        visit[x][y]=1; count++;
      } 
      if(map[x][y]!=0 && map[x][y]<size) {
        if(!find) {
          move.first=x; move.second=y;
          find=true;
        } else if(move.second>y) {
          move.first=x; move.second=y;
        } else if(move.second==y && move.first>x) {
          move.first=x; move.second=y;
        }
      }
    }
    now--;
  }
  cout<<time<<'\n';
  return 0;
}