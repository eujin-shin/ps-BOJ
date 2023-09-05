#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack <int> s;
vector <int> v[100001];
int visit[100001]={0, }, parent[100001]={0, }, child[100001]={1, };

int main() {
  ios_base::sync_with_stdio(false);
  int n, x, y, cnt, p, flag=1;
  cin>>n;
  for(int i=0; i<n-1; i++) {
    cin>>x>>y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  s.push(0);
  for(int i=1; i<=n; i++) {
    cin>>x;
    p=s.top();
    if(i==1 && x!=1) {
      flag=0; break;
    }
    if(parent[x]!=p) {
      flag=0; break;
    }
    visit[x]=i; cnt=0;
    for(int j=0; j<v[x].size(); j++) {
      y=v[x][j];
      if(visit[y]!=0) continue;
      cnt++; parent[y]=i;
    }
    child[i]=cnt;
    child[p]--;
    if(child[p]==0) s.pop();
    if(child[i]!=0) s.push(i);
  }
  cout<<flag<<'\n';
  return 0;
}