#include <iostream>
#include <queue>
using namespace std;

int map[9][9] = {0, };
int x_move[] = {0, 1, -1, 0};
int y_move[] = {1, 0, 0, -1};
int num_arr[6] = {0, };

void BFS() {
  int n = num_arr[1], m = num_arr[2], result;
  queue <int> xq; queue <int> yq;
  int area = 0, cur_x, cur_y, next_x, next_y;
  bool flag;
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      if(map[x][y]==2) {
        xq.push(x); yq.push(y);
        flag = false;
        while(!xq.empty()) {
          cur_x = xq.front(); xq.pop();
          cur_y = yq.front(); yq.pop();
          if(flag && map[cur_x][cur_y]!=0) continue;
          flag = true;
          if(map[cur_x][cur_y]==0) {
            map[cur_x][cur_y] = -1;
            area++;
          }
          for(int i=0; i<4; i++) {
            next_x = cur_x + x_move[i];
            next_y = cur_y + y_move[i];
            if(next_y<n && next_y>=0 && next_x<m && next_x>=0 && map[next_x][next_y]==0) {
              xq.push(next_x); yq.push(next_y);
            }
          }
        }
      }
    }
  }
  for(int y=0; y<n; y++) {
    for(int x=0; x<m; x++) {
      if(map[x][y]==-1) {
        map[x][y] = 0;
      }
    }
  }
  int wall = num_arr[3], virus = num_arr[4];
  result = n*m-wall-area-virus;
  if(num_arr[0]<result) {
    num_arr[0] = result;
  }
  return;
}

void BackTrack(int x, int y, int r) {
  int n = num_arr[1], m = num_arr[2];
  if(r==3) {
    BFS();
  } else {
    // 이중 루프에서 초기화 조건을 i=y, j=x로 둘 경우, 다음 행으로 넘어갔을 때 y+1, 0부터 탐색하는 것이 아니라 y+1, x부터 시작하기 때문에 완전히 탐색이 불가능하다.
    for(int i=x; i<m; i++) {
      if(map[i][y]==0) {
        map[i][y] = 1;
        BackTrack(i, y, r+1);
        map[i][y] = 0;
      }
    }
    for(int i=y+1; i<n; i++) {
      for(int j=0; j<m; j++) {
        if(map[j][i]==0) {
          map[j][i] = 1;
          BackTrack(j, i, r+1);
          map[j][i] = 0;
        }
      }
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, virus, wall=3;
  cin>>n>>m;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[j][i];
      if(map[j][i]==1) wall++;
      else if(map[j][i]==2) virus++;
    }
  }
  num_arr[1] = n; num_arr[2] = m; num_arr[3] = wall; num_arr[4] = virus;
  BackTrack(0, 0, 0);
  cout<<num_arr[0]<<'\n';
  return 0;
}