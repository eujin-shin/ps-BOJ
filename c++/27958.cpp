#include <iostream>
using namespace std;

int n, k, ans=0;
int tmp[2][8][8]={0, }, arr[5]={0, };
int xmove[4]={0, 1, 0, -1}, ymove[4]={1, 0, -1, 0};

int Shoot(int k, int r, int m[][8][8]) {
  int power=arr[r], point=0, x, y;
  for(int h=0; h<2; h++) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) tmp[h][i][j]=m[h][i][j];
    }
  } 
  for(int i=0; i<n; i++) {
    if(tmp[1][k][i]==0) continue;
    else if(tmp[1][k][i]>9) {
      point=tmp[0][k][i]; tmp[1][k][i]=0; break;
    } else if(tmp[1][k][i]>power) {
      tmp[1][k][i]-=power; break;
    } else {
      point=tmp[0][k][i]; tmp[1][k][i]=0; 
      if(point/4<1) break;
      for(int j=0; j<4; j++) {
        x=i+xmove[j]; y=k+ymove[j];
        if(x<0 || y<0 || x>=n || y>=n || tmp[1][y][x]!=0) continue;
        tmp[0][y][x]=point/4;
        tmp[1][y][x]=point/4;
      }
      break;
    }
  }
  return point;
}

void Solve(int r, int score, int m[][8][8]) {
  int cur[2][8][8]={0, }, point;
  if(r==k) {
    if(score>ans) ans=score; return;
  } 
  for(int h=0; h<2; h++) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) cur[h][i][j]=m[h][i][j];
    }
  }
  for(int i=0; i<n; i++) {
    point=Shoot(i, r, cur);
    Solve(r+1, score+point, tmp);
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin>>n>>k;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin>>tmp[0][i][j];
      tmp[1][i][j]=tmp[0][i][j];
    }
  }
  for(int i=0; i<k; i++) cin>>arr[i];
  Solve(0, 0, tmp);
  cout<<ans<<'\n';
  
  return 0;
}