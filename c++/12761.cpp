#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int arr[8]={0, };

void GetNext(int a, int b, int x) {
  arr[0]=x-1; arr[1]=x+1;
  arr[2]=x-a; arr[3]=x+a;
  arr[4]=x-b; arr[5]=x+b;
  arr[6]=x*a; arr[7]=x*b;
  return;
}

int main() {
  int visit[MAX+1]={0, };
  int a, b, n, m;
  cin>>a>>b>>n>>m;
  int cur=-1, next, turn=0, now=1, count=0;
  queue <int> q; q.push(n); visit[n]=1;
  while(!q.empty()) {
    if(now==0) {
      now=count; count=0; turn++;
    }
    cur=q.front(); q.pop();
    if(cur==m) break;
    GetNext(a, b, cur);
    for(int i=0; i<8; i++) {
      next=arr[i];
      if(next<0 || next>MAX) continue;
      if(visit[next]==0) {
        count++; visit[next]=1; q.push(next);
      }
    }
    now--;
  }
  cout<<turn<<'\n';
  return 0;
}