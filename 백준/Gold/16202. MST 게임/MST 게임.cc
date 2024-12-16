#include <iostream>
#include <vector>
#define pnt pair<int, int>
#define DISCARD -1
using namespace std;

vector <pnt> edges;
int parent[10001] = {0, }, edgeState[10001] = {0, };

void initParent(int n) {
  for(int i = 1; i <= n; i++) {
    parent[i] = i;
  }
}

int find(int x) {
  if(parent[x] == x) {
    return x;
  }
  return find(parent[x]);
}

void setParent(int n, int currentParent, int newParent) {
  for(int i = 1; i <= n; i++) {
    if(parent[i] == currentParent) {
      parent[i] = newParent;
    }
  }
  return;
}

bool unionGraph(int n, int x, int y) {
  int a = find(x), b = find(y);
  if(a == b) {
    return false;
  }
  if(a < b) {
    setParent(n, b, a);
  } else {
    setParent(n, a, b);
  }
  return true;
}

int main() {
  int n, m, k;
  cin>>n>>m>>k;

  int x, y, w;
  for(w = 1; w <= m; w++) {
    cin>>x>>y;
    edges.push_back(make_pair(x, y));
  }

  bool able = true, checkedMinEdge;
  int score, count;
  for(int i = 0; i < k; i++) {
    if(i > 0) {
      cout<<" ";
    }
    if(able) {
      initParent(n);
      checkedMinEdge = false;
      count = 0;
      score = 0;

      for(int i = 0; i < m; i++) {
        if(edgeState[i] == DISCARD) {
          continue;
        }
        if(unionGraph(n, edges[i].first, edges[i].second)) {
          if(!checkedMinEdge) {
            checkedMinEdge = true;
            edgeState[i] = DISCARD;
          }
          score += i + 1;
          count++;
        }
      }

      if(count == n - 1) {
        cout<<score;
      } else {
        able = false;
      }
    } 
    if(!able) {
      cout<<0;
    }
  }
  cout<<'\n';
  return 0;
}
