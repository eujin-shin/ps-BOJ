#include <iostream>
#include <queue>
using namespace std;

int main() {
  queue <int> q;
  int visit[100001] = {0, };
  int n, k;
  cin>>n>>k;
  int cur, next, now, count = 0, time = 0;
  bool flag = false;
  q.push(n);
  if(n==k) {
    cout<<"0\n1\n"; return 0;
  }
  now = 1; next = 0;
  while(!q.empty()) {
    cur = q.front(); q.pop();
    if(cur==k) {
      if(!flag) flag = true;
      count++;
    } else visit[cur] = 1;
    if(cur-1>=0 && !visit[cur-1]) {
      q.push(cur-1); next++;
    }
    if(cur+1<=100000 && !visit[cur+1]) {
      q.push(cur+1); next++;
    }
    if(cur*2<=100000 && !visit[cur*2]) {
      q.push(cur*2); next++;
    }
    now--;
    if(now==0) {
      if(flag) break;
      now = next; next = 0; time++;
    }
  }
  cout<<time<<'\n'<<count<<'\n';
  return 0;
}