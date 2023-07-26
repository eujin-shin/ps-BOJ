#include <iostream>
#include <stack>
using namespace std;

int up(int n, int cur, int map[][20], int next[][20]) {
  int index, max=cur, now;
  for(int x=0; x<n; x++) {
    index=0;
    for(int y=0; y<n; y++) {
      now=map[x][y];
      if(now==0) continue;
      if(next[x][index]==0) {
        next[x][index]=now;
      } else if(next[x][index]==now) {
        next[x][index]=now*2;
        if(now*2>max) max=now*2;
        index++;
      } else {
        index++;
        next[x][index]=now;
      }
    } 
  }
  return max;
}

int down(int n, int cur, int map[][20], int next[][20]) {
  int index, max=cur, now;
  for(int x=0; x<n; x++) {
    index=n-1;
    for(int y=n-1; y>-1; y--) {
      now=map[x][y];
      if(now==0) continue;
      if(next[x][index]==0) {
        next[x][index]=now;
      } else if(next[x][index]==now) {
        next[x][index]=now*2;
        if(now*2>max) max=now*2;
        index--;
      } else {
        index--;
        next[x][index]=now;
      }
    }
  }
  return max;
}

int right(int n, int cur, int map[][20], int next[][20]) {
  int index, max=cur, now;
  for(int y=0; y<n; y++) {
    index=n-1;
    for(int x=n-1; x>-1; x--) {
      now=map[x][y];
      if(now==0) continue;
      if(next[index][y]==0) {
        next[index][y]=now;
      } else if(next[index][y]==now) {
        next[index][y]=now*2;
        if(now*2>max) max=now*2;
        index--;
      } else {
        index--;
        next[index][y]=now;
      }
    }
  }
  return max;
}

int left(int n, int cur, int map[][20], int next[][20]) {
  int index, max=cur, now;
  for(int y=0; y<n; y++) {
    index=0;
    for(int x=0; x<n; x++) {
      now=map[x][y];
      if(now==0) continue;
      if(next[index][y]==0) {
        next[index][y]=now;
      } else if(next[index][y]==now) {
        next[index][y]=now*2;
        if(now*2>max) max=now*2;
        index++;
      } else {
        index++;
        next[index][y]=now;
      }
    }
  }
  return max;
}

void play(int n, int r, int x, int *max, int map[][20]) {
  if(r==5) {
    if(x>*max) *max=x;
    return;
  } 
  int temp;
  for(int i=0; i<4; i++) {
    int next[20][20]={0, };
    if(i==0) {
      temp=up(n, x, map, next);
    } else if(i==1) {
      temp=down(n, x, map, next);
    } else if(i==2) {
      temp=right(n, x, map, next);
    } else if(i==3) {
      temp=left(n, x, map, next);
    }
    play(n, r+1, temp, max, next);
  }
  return;
}

int main() {
  int map[20][20]={0, };
  int n, max=0;
  cin>>n;
  for(int y=0; y<n; y++) {
    for(int x=0; x<n; x++) {
      cin>>map[x][y];
      if(map[x][y]>max) max=map[x][y];
    }
  }
  play(n, 0, max, &max, map);
  cout<<max<<'\n';
  return 0;
}