#include <iostream>
#include <queue>
using namespace std;

int arr[1000]={0, };
queue <int> q;

int Push(int x, int c) {
  q.push(x); arr[x]=1;
  return c+1;
}

int main() {
  int a, b, n, tmp, cur, level=1, count=0, next=0;
  cin>>a>>b>>n;
  if(a==b) {
    cout<<"0\n"; return 0;
  }
  arr[a]=1;
  if(a-1>0) next=Push(a-1, next);
  if(a+1<1000) next=Push(a+1, next);
  for(int i=0; i<n; i++) {
    cin>>tmp; 
    if(arr[tmp]==0) next=Push(tmp, next); 
  }
  while(!q.empty()) {
    cur=q.front(); q.pop();
    if(cur==b) break;
    if(cur-1>0 && arr[cur-1]==0) count=Push(cur-1, count);
    if(cur+1<1000 && arr[cur+1]==0) count=Push(cur+1, count);
    next--;
    if(next==0) {
      level++; next=count; count=0;
    }
  }
  cout<<level<<'\n';
  return 0;
}