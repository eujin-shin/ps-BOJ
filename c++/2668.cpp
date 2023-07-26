#include <iostream>
#include <queue>
using namespace std;

int arr[101] = {0, };
int visit[101] = {0, };

void DFS(queue<int> q, int cur, int *c) {
  if(!q.empty() && cur==q.front()) {
    int x;
    *c = *c + q.size();
    while(!q.empty()) {
      x = q.front(); q.pop();
      arr[x] = 0;
    }
  } else {
    q.push(cur);
    int next = arr[cur];
    if(next!=q.front() && visit[next]==1 || next==0) return; 
    visit[cur]=1;
    DFS(q, arr[cur], c);
    visit[cur]=0;
  }
  return;
}

int Cmp(const void *a, const void *b) {
  return *(int *)a-*(int *)b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, len;
  cin>>n;
  for(int i=1; i<=n; i++) {
    cin>>arr[i];
  }
  int count = 0;
  for(int i=1; i<=n; i++) {
    if(arr[i]!=0) {
      queue<int> q;
      DFS(q, i, &count);
    }
  }
  cout<<count<<'\n';
  for(int i=1; i<=n; i++) {
    if(arr[i]==0) cout<<i<<'\n';
  }
  return 0;
}