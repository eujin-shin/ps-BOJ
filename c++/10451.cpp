#include <iostream>
using namespace std;

int graph[1003][1003] = {0, };

void DFS(int v, int n) {
  graph[v][0] = 1;
  for(int i=1; i<=n; i++) {
    if(graph[v][i]==1 && graph[i][0]==0) {
      graph[v][i] = 0;
      DFS(i, n);
      break;
    }
  }
}

int main() {
  int t, n, x, count;
  cin>>t;
  for(int i=0; i<t; i++) {
    count = 0;
    cin>>n;
    for(int j=1; j<=n; j++) {
      cin>>x;
      graph[j][x] = 1;
    }
    for(int j=1; j<=n; j++) {
      if(graph[j][0]==0) {
        DFS(j, n);
        count++;
      }
    }
    for(int j=1; j<=n; j++) {
      graph[j][0] = 0;
    }
    cout<<count<<endl;
  }
  return 0;
}