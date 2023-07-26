#include <iostream>
#include <queue>
using namespace std;

typedef struct CUR {
  int p, s, b;
} cur;
int m=0, n;

queue <cur> q;

void DFS(int r, int s, int p, int b) {
  if(r==n) {
    if(m<p) m=p;
    return;
  }
  DFS(r+1, s, p+1, b); 
  if(p>0) DFS(r+1, p, p, b);
  if(s>0) DFS(r+1, 0, p, s);
  if(b>0) DFS(r+1, 0, p+b, b);
  return;
}

int main() {
  cin>>n;
  int p, s, b;
  cur x;
  x.b=0; x.p=0; x.s=0;
  q.push(x);
  while(!q.empty()) {
    p=q.front().p; s=q.front().s; b=q.front().b;
    q.pop();
    
  }
  cout<<m<<'\n';
  return 0;
}