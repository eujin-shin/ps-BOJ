#include <iostream>
#include <queue>
using namespace std;

int main() {
  int visit[1001][1001]={0, };
  int s, cur, board, time=0, count=0, now=1;
  cin>>s;
  queue <pair<int, int> > q; 
  q.push(make_pair(1, 0));
  visit[1][0]=1;
  while(!q.empty()) {
    cur=q.front().first; board=q.front().second;
    q.pop();
    if(cur==s) break;
    if(cur>0 && cur<s && visit[cur][cur]==0) {
      visit[cur][cur]=1;
      q.push(make_pair(cur, cur));
      count++;
    }
    if(board>0 && cur<s && visit[cur+board][board]==0) {
      visit[cur+board][board]=1;
      q.push(make_pair(cur+board, board));
      count++;
    }
    if(cur>0 && visit[cur-1][board]==0) {
      visit[cur-1][board]=1;
      q.push(make_pair(cur-1, board));
      count++;
    }
    now--;
    if(now==0) {
      now=count; count=0; time++;
    }
  }
  cout<<time<<'\n';
  return 0;
}