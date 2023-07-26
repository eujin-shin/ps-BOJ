#include <iostream>
#include <vector>
using namespace std;

vector <int> v[2000];

void Btk(int* flag, int visit[], int r, int x) {
  if(*flag) return;
  if(r==5) {
   *flag = 1;
   return;
  } else {
    for(int i=0; i<v[x].size(); i++) {
      if(visit[v[x][i]]==0) {
        visit[v[x][i]] = 1;
        Btk(flag, visit, r+1, v[x][i]);
        visit[v[x][i]] = 0;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin>>n>>m;
  for(int i=0; i<m; i++) {
    cin>>a>>b;
    v[a].push_back(b); v[b].push_back(a);
  }
  int flag = 0;
  for(int i=0; i<n; i++) {
    int visit[2000] = {0, };
    visit[i] = 1;
    Btk(&flag, visit, 1, i);
    if(flag) break;
  }
  cout<<flag<<'\n';
  return 0;
}