#include <iostream>
#include <queue>
using namespace std;

int main() {
  int visit[100001] = {0, };
  int n, k, cur, time = 0, next = 0, now = 1;
  cin>>n>>k;
  queue <int> q; q.push(n);
  visit[n] = 1;
  while(n!=k) {
    cur = q.front(); q.pop();
    visit[cur]=1;
    if(cur-1==k || cur+1==k || cur*2==k) break;
    if(cur-1>=0 && cur-1<=100000 && visit[cur-1]==0) {
      q.push(cur-1); next++;
    }
    if(cur+1>=0 && cur+1<=100000 && visit[cur+1]==0) {
      q.push(cur+1); next++;
    }
    if(cur*2>=0 && cur*2<=100000 && visit[cur*2]==0) {
      q.push(cur*2); next++;
    }
    now--;
    if(now==0) {
      now=next; next=0; time++;
    }
  }
  if(n==k) time=-1;
  cout<<time+1<<'\n';
  return 0;
}