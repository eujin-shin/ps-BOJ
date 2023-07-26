#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> friends[52];
int score[52] = {0, };

int main() {
  int n, a, b;
  cin>>n>>a>>b;
  while(a+b!=-2) {
    friends[a].push_back(b);
    friends[b].push_back(a);
    cin>>a>>b;
  }
  int now, next, count, x, y, f, min=0, c=0;
  queue <int> q;
  for(int i=1; i<=n; i++) {
    int visit[52]={0, };
    now=1, next=0, count=0, f=n;
    q.push(i); visit[i]=1;
    while(!q.empty()) {
      if(now==0) {
        now=next; next=0; count++;
      }
      x = q.front(); q.pop(); f--;
      for(int j=0; j<friends[x].size(); j++) {
        y = friends[x][j];
        if(visit[y]==0) {
          visit[y]=1; next++;
          q.push(y);
        }
      }
      now--;
    }
    if(f==0) {
      score[i]=count;
      if(min==0 || min>count) {
        min=count; c=1;
      } else if(min==count) {
        c++;
      }
    }
  }
  cout<<min<<' '<<c<<'\n';
  for(int i=1; i<=n; i++) {
    if(score[i]==min) {
      cout<<i; c--;
      if(c==0) cout<<'\n';
      else cout<<' ';
    }
  }
  return 0;
}