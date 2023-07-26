#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[25]={0, }, visit[25]={0, };
int arr[7]={0, };
int m[4]={1, -1, 5, -5};

int Check() {
  queue <int> q;
  int cur, next, v=0, x, y;
  q.push(arr[0]); visit[arr[0]]=0;
  while(!q.empty()) {
    cur=q.front(); q.pop(); v++;
    x=cur%5; y=cur/5;
    for(int i=0; i<4; i++) {
      next=cur+m[i];
      if(next<0 || next>24 || (next/5!=y && next%5!=x)) continue; 
      if(visit[next]>=0) continue;
      visit[next]=0; q.push(next);
    }
  }
  for(int i=0; i<7; i++) visit[arr[i]]=-1;
  if(v>=7) return 1;
  return 0;
}

int Btr(int k, int r, int c) {
  int result=0;
  if(r==7) {
    if(c<4) return 0;
    result=Check();
    // cout<<result<<'\n';  
  } else {
    for(int i=k; i<25; i++) {
      arr[r]=i; visit[i]=-1;
      result+=Btr(i+1, r+1, c+map[i]);
      visit[i]=0;
    }
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  string in;
  int ans=0, temp;
  for(int y=0; y<5; y++) {
    cin>>in;
    for(int x=0; x<5; x++) {
      if(in[x]=='Y') continue;
      map[y*5+x]=1;
    }
  }
  cout<<Btr(0, 0, 0)<<'\n';
  return 0;
}

/*
00000
00101
00111
01001
00000
*/