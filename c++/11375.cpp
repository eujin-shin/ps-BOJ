#include <iostream>
#include <vector>
#define M 1001
using namespace std;

vector <int> v[M];
int arr[M]={0, };
bool visit[M];

bool DFS(int x) {
  int p;
  for(int i=0; i<v[x].size(); i++) {
    p=v[x][i];
    if(visit[p]) continue;
    visit[p]=true;
    if(arr[p]==0 || DFS(arr[p])) {
      arr[p]=x; return true;
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  int n, m, k, x, c;
  cin>>n>>m;
  for(int i=1; i<=n; i++) {
    cin>>k;
    for(int j=0; j<k; j++) {
      cin>>x;
      v[i].push_back(x);
    }
  }
  c=0;
  for(int i=1; i<=n; i++) {
    fill(visit, visit+M, false);
    if(DFS(i)) c++;
  }
  cout<<c<<'\n';
  return 0;
}