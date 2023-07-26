#include <iostream>
#include <queue>
using namespace std;

typedef struct {
  int time, dir;
} change;

int x_move[4] = {1, 0, -1, 0};
int y_move[4] = {0, 1, 0, -1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int map[102][102] = {0, };
  int n, k, l, x, y;
  char c;
  cin>>n>>k;
  for(int i=0; i<k; i++) {
    cin>>y>>x;
    map[x][y] = 2;
  }
  change data[101] = {0, };
  cin>>l;
  for(int i=0; i<l; i++) {
    cin>>data[i].time>>c;
    if(c=='L') data[i].dir = -1;
    else data[i].dir = 1;
  }
  x = 1; y = 1;
  map[1][1] = 1;
  queue <int> xq; queue <int> yq;
  xq.push(1); yq.push(1);
  int time=0, dir=0, i=0, x_tail=1, y_tail=1;
  while(1) {
    time++;
    x += x_move[dir]; y += y_move[dir];
    if(x>n || y>n || x<1 || y<1 || map[x][y]==1) break;
    if(map[x][y]==0) {
      x_tail = xq.front(); y_tail = yq.front();
      xq.pop(); yq.pop();
      map[x_tail][y_tail] = 0;
    }
    map[x][y] = 1;
    xq.push(x); yq.push(y);
    if(i<l && time==data[i].time) {
      dir += data[i].dir;
      if(dir<0) dir = 3; else if(dir>3) dir = 0;
      i++;
    }
  }
  cout<<time<<'\n';
  return 0;
}