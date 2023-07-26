#include <iostream>
#include <queue>
#define M 100002
using namespace std;

int arr[M]={0, };

int main() {
  int n, k, cur, next, count, now, time=0;
  cin>>n>>k;
  queue <int> q; q.push(n); now=1;
  while(!q.empty()) {
    cur=q.front(); q.pop(); count=0;
    while(cur<=M) {
      if(cur==k) break;
      arr[cur]=1;
      if(cur!=0 && arr[cur-1]==0) {
        arr[cur-1]=1; q.push(cur-1); count++;
      }
      if(cur!=M-1 && arr[cur+1]==0) {
        arr[cur+1]=1; q.push(cur+1); count++;
      }
      cur*=2;
    }
    if(cur==k) break;
    now--;
    if(now==0) {
      now=count; count=0; time++;
    }
  }
  cout<<time<<'\n';
  return 0;
}