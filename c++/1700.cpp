#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define pnt pair<int, int>
#define M 101
using namespace std;

int arr[M]={0, }, tap[M]={0, };
vector <int> v[M];

void Change(int k) {
  int index, max=0, next;
  for(int i=1; i<=k; i++) {
    if(tap[i]==0) continue;
    if(v[i].size()==0) next=M;
    else next=v[i][0];
    if(next<max) continue;
    max=next; index=i;
  }
  tap[index]=0;
  return;
}

int main() {
  int n, k, cur, next, ans=0, count=0;
  cin>>n>>k;
  for(int i=1; i<=k; i++) {
    cin>>arr[i]; v[arr[i]].push_back(i);
  }
  priority_queue <pnt, vector<pnt>, less<pnt> > pq;
  for(int i=1; i<=k; i++) {
    cur=arr[i]; 
    v[cur].erase(v[cur].begin());
    if(tap[cur]==0) {
      if(count<n) count++;
      else {
        Change(k); ans++;
      }
      tap[cur]=1;
    }
  }
  cout<<ans<<'\n';
  return 0;
}