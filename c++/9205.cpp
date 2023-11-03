#include <iostream>
#include <vector>
#include <queue>
#define pnt pair<int, int>
using namespace std;

int Distance(pnt a, pnt b) {
  return ((a.first>b.first) ? (a.first-b.first) : (b.first-a.first))+((a.second>b.second) ? (a.second-b.second) : (b.second-a.second));
}

int main() {
  int t, n, x, y, visit[100]={0, };
  pnt cur, end;
  bool flag;
  cin>>t;
  while(t--) {
    vector <pnt> v;
    queue <pnt> q;
    flag=false;
    cin>>n;
    cin>>x>>y;
    q.push(make_pair(x, y));
    for(int i=0; i<n; i++) {
      cin>>x>>y;
      v.push_back(make_pair(x, y));
      visit[i]=0;
    }
    cin>>x>>y;
    end.first=x; end.second=y;
    while(!q.empty()) {
      cur=q.front(); q.pop();
      if(Distance(cur, end)<=1000) {
        flag=true; break;
      }
      for(int i=0; i<n; i++) {
        if(visit[i]!=0) continue;
        if(Distance(cur, v[i])<=1000) {
          q.push(v[i]); visit[i]=1;
        }
      }
    }
    if(flag) cout<<"happy\n";
    else cout<<"sad\n";
  }
  return 0;
}