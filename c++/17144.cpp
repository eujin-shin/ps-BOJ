#include <iostream>
#include <cstring>
using namespace std;

int room[52][52] = {0, };
int tmp[52][52]={0, };

int x_move[4] = {1, 0, -1, 0};
int y_move[4] = {0, 1, 0, -1};

void Spread(int x, int y, int r, int c) {
  int amount, count=0, next_x, next_y;
  amount = room[x][y]/5;
  for(int i=0; i<4; i++) {
    next_x = x+x_move[i]; next_y = y+y_move[i];
    if(next_x>c || next_x<1 || next_y>r || next_y<1) continue;
    if(room[next_x][next_y]>=0) {
      count++;
      tmp[next_x][next_y] += amount;
    }
  }
  room[x][y] = room[x][y] - (amount*count);
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, t, air;
  cin>>r>>c>>t;
  for(int i=1; i<=r; i++) {
    for(int j=1; j<=c; j++) {
      cin>>room[j][i];
      if(room[j][i]==-1) air = i;
    }
  }
  int next, temp, x, y, dir;
  for(int i=0; i<t; i++) {
    for(int y=1; y<=r; y++) {
      for(int x=1; x<=c; x++) {
        if(room[x][y]>0) {
          Spread(x, y, r, c);
        }
      }
    }
    for(int y=1; y<=r; y++) {
      for(int x=1; x<=c; x++) {
        room[x][y]+=tmp[x][y];
        tmp[x][y]=0;
      }
    }
    x = 2; y = air-1; dir = 0; next = 0;
    while(x!=1 || y!=air-1) {
      temp = room[x][y]; room[x][y] = next;
      next = temp;
      if(x==c && y==air-1) {
        dir = 3;
      } else if(x==c && y==1) {
        dir = 2;
      } else if(x==1 && y==1) {
        dir = 1;
      }
      x += x_move[dir]; y += y_move[dir];
    }
    x = 2; y = air; dir = 0; next = 0;
    while(x!=1 || y!=air) {
      temp = room[x][y]; room[x][y] = next;
      next = temp;
      if(x==c && y==air) {
        dir = 1;
      } else if(x==c && y==r) {
        dir = 2;
      } else if(x==1 && y==r) {
        dir = 3;
      }
      x += x_move[dir]; y += y_move[dir];
    }
  }
  int ans = 0;
  for(int y=1; y<=r; y++) {
    for(int x=1; x<=c; x++) {
      if(room[x][y]>0) ans+=room[x][y];
    }
  }
  cout<<ans<<'\n';
  return 0;
}