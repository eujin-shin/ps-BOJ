#include <iostream>
#include <vector>
#define M 50001
using namespace std;

vector <int> outd[M];
int parent[M]={0, }, level[M]={0, };

void MakeTree(int x, int l) {
  int child;
  level[x]=l;
  for(int i=0; i<outd[x].size(); i++) {
    child=outd[x][i];
    if(level[child]!=0) continue;
    parent[child]=x;
    MakeTree(child, l+1);
  }
  return;
}

int GetAn(int a, int b) {
  int temp;
  if(level[b]<level[a]) {
    temp=b; b=a; a=temp;
  }
  while(level[a]<level[b]) {
    b=parent[b];
  }
  while(a!=b) {
    a=parent[a]; b=parent[b];
  }
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin>>n;
  for(int i=0; i<n-1; i++) {
    cin>>a>>b;
    outd[a].push_back(b); outd[b].push_back(a);
  }
  MakeTree(1, 1);
  cin>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    cout<<GetAn(a, b)<<'\n';
  }
  return 0;
}