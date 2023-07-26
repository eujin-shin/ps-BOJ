#include <iostream>
#include <queue>
using namespace std;

int main() {
  int visit[1000001]={0, };
  int move[2]={0, };
  int f, s, g, cur;
  bool fail=true;
  cin>>f>>s>>g>>move[0]>>move[1];
  move[1]=-move[1];
  queue <int> q;
  q.push(s); visit[s]=1;
  int level=0, next=0, now=1, m;
  while(!q.empty()) {
    if(now==0) {
      now=next; next=0; level++;
    }
    cur=q.front(); q.pop();
    if(cur==g) {
      fail=false; break;
    }
    for(int i=0; i<2; i++) {
      m=cur+move[i];
      if(m<1 || m>f || visit[m]) continue;
      visit[m]=1;
      q.push(m); next++;
    }
    now--;
  }
  if(fail) cout<<"use the stairs\n";
  else cout<<level<<'\n';
  return 0;
}