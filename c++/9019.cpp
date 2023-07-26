#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int visit[10000];
string path[10000];
int tmp[4];

int D(int x) {
  if(x*2>=10000) return (x*2)%10000;
  return x*2;
}

int S(int x) {
  if(x==0) return 9999;
  return x-1;
}

int L(int x) {
  int tmp=x/1000;
  return (x%1000)*10+tmp;
}

int R(int x) {
  int tmp=x%10;
  return x/10+tmp*1000;
}

void Solve(int a, int b) {
  int cur, next;
  queue <int> q;
  q.push(a); visit[a]=1; path[a]="";
  while(!q.empty()) {
    cur=q.front(); q.pop();
    next=D(cur); 
    if(visit[next]==0) {
      path[next]=path[cur]+"D"; visit[next]=1;
      q.push(next);
    }
    next=S(cur);
    if(visit[next]==0) {
      path[next]=path[cur]+"S"; visit[next]=1;
      q.push(next);
    }
    next=R(cur);
    if(visit[next]==0) {
      path[next]=path[cur]+"R"; visit[next]=1;
      q.push(next);
    }
    next=L(cur);
    if(visit[next]==0) {
      path[next]=path[cur]+"L"; visit[next]=1;
      q.push(next);
    }
    if(visit[b]!=0) break;
  }
  cout<<path[b]<<'\n';
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, a, b;
  cin>>t;
  while(t--) {
    cin>>a>>b;
    memset(visit, 0, sizeof(visit));
    Solve(a, b);
  }
  return 0;
}