#include <iostream>
using namespace std;

int dice[6] = {0, }; // 0: 위, 1: 동, 2: 서, 3: 남, 4: 북, 5: 밑
int map[21][21] = {0, };
int x_move[5] = {0, 1, -1, 0, 0};
int y_move[5] = {0, 0, 0, -1, 1};
int opp[5] = {0, 2, 1, 4, 3};

void Change(int a, int b) {
  int temp = dice[a];
  dice[a] = dice[b];
  dice[b] = temp;
  return;
}

void Move_Dice(int m, int n, int d) {
  int x = x_move[0]+x_move[d], y = y_move[0]+y_move[d];
  if(x>=m || y>=n || x<0 || y<0) return;
  x_move[0] = x; y_move[0] = y;
  Change(0, d); Change(5, opp[d]); Change(0, 5);
  if(map[x][y]==0) map[x][y] = dice[5];
  else {
    dice[5] = map[x][y];
    map[x][y] = 0;
  }
  cout<<dice[0]<<'\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, x, y, k, temp;
  int ans_arr[1000] = {0, };
  cin>>n>>m>>y>>x>>k;
  x_move[0] = x; y_move[0] = y;
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin>>map[j][i];
    }
  }
  for(int i=0; i<k; i++) {
    cin>>temp;
    Move_Dice(m, n, temp);
  }
  
  return 0;
}