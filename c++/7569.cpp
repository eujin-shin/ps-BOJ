#include <iostream>
#include <queue>
using namespace std;

typedef struct {
  int x, y, z;
} pos;

int x_move[6]={-1, 1, 0, 0, 0, 0};
int y_move[6]={0, 0, -1, 1, 0, 0};
int z_move[6]={0, 0, 0, 0, -1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  int map[100][100][100]={0, };
  int m, n, h, x, y, z, nx, ny, nz, t=0;
  cin>>m>>n>>h;
  queue <pos> q;
  for(int z=0; z<h; z++) {
    for(int y=0; y<n; y++) {
      for(int x=0; x<m; x++) {
        cin>>map[x][y][z];
        if(map[x][y][z]==1) {
          pos to;
          to.x=x; to.y=y; to.z=z;
          q.push(to);
        } else if(map[x][y][z]==0) {
          t++;
        }
      }
    }
  }
  if(t==0) {
    cout<<"0\n"; return 0;
  }
  int cur=q.size(), qu=0, level=1;
  while(!q.empty()) {
    x=q.front().x; y=q.front().y; z=q.front().z; q.pop();
    for(int i=0; i<6; i++) {
      nx=x+x_move[i];
      ny=y+y_move[i];
      nz=z+z_move[i];
      if(nx<0 || nx>=m || ny<0 || ny>=n || nz<0 || nz>=h) continue;
      if(map[nx][ny][nz]==0) {
        map[nx][ny][nz]=1;
        pos next;
        next.x=nx; next.y=ny; next.z=nz;
        q.push(next);
        t--; qu++;
      }
    }
    if(t==0) break;
    cur--;
    if(cur==0) {
      cur=qu; qu=0; level++;
    }
  }
  if(t>0) cout<<"-1\n";
  else cout<<level<<'\n';
}