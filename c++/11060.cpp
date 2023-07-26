#include <iostream>
#include <queue>
using namespace std;

int main() {
  int arr[1001]={0, };
  int visit[1001]={0, };
  int n, ans=-1, count, cur, next, pos;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>arr[i];
  }
  queue <int> q;
  count=0; cur=1; next=0;
  q.push(1); visit[1]=-1;
  while(!q.empty()) {
    pos=q.front(); q.pop();
    if(pos>=n) {
      ans=count; break;
    } else if(pos+arr[pos]>=n) {
      ans=count+1; break;
    }
    for(int i=1; i<=arr[pos]; i++) {
      if(visit[pos+i]==1) continue;
      next++; q.push(pos+i); visit[pos+i]=1; 
    }
    cur--;
    if(cur==0) {
      count++; cur=next; next=0;
    }
  }
  cout<<ans<<'\n';
  return 0;
}