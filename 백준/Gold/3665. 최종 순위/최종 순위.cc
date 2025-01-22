#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n;
  cin>>t;
  while(t--) {
    cin>>n;
    solve(n);
  } 
  return 0;
}

void solve(int n) {
  int map[501][501] = {0, };
  int front[501] = {0, };
  int x, y;
  for(int i = 1; i <= n; i++) {
    cin>>x;
    front[x] = i;
    for(int j = 1; j <= n; j++) {
      map[x][j] = front[j] == 0 ? 1 : 0;
    }
    map[x][x] = 1;
  }
  int m, temp;
  cin>>m;
  for(int i = 0; i < m; i++) {
    cin>>x>>y;
    temp = map[x][y];
    map[x][y] = map[y][x];
    map[y][x] = temp;

    if(temp == 1) {
      front[x]++;
      front[y]--;
    } else {
      front[x]--;
      front[y]++;
    }
  }

  vector <pair<int, int> > v;
  for(int i = 1; i <= n; i++) {
    v.push_back(make_pair(front[i], i));
  }
  sort(v.begin(), v.end());

  bool isPossible = true;
  for(int i = 0; i < n && isPossible; i++) {
    isPossible = v[i].first == i + 1;
    x = v[i].second;
    for(y = 1; y <= n && isPossible; y++) {
      isPossible = (front[y] < front[x] && map[x][y] == 0) || (front[y] >= front[x] && map[x][y]== 1);
    }
  }

  if(isPossible) {
    for(int i = 0; i < n; i++) {
      if(i > 0) {
        cout<<' ';
      }
      cout<<v[i].second;
    }
    cout<<'\n';
  } else {
    cout<<"IMPOSSIBLE\n";
  }
  return;
}