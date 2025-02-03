#include <iostream>
#include <vector>
using namespace std;

int solve(int n);

int main() {
  int t, n;
  cin>>t;
  while(t--) {
    cin>>n;
    cout<<solve(n)<<'\n';
  }
  return 0;
}

int solve(int n) {
  vector <int> teams[201], orders;
  int x, teamCount = 1;
  for(int i = 0; i < n; i++) {
    cin>>x;
    teams[x].push_back(i);
    orders.push_back(x);
    teamCount = (x > teamCount ? x : teamCount);
  }

  int scores[201][3] = {0, };
  int cur = 1;
  for(int i = 0; i < n; i++) {
    x = orders[i];
    if(teams[x].size() == 6) {
      scores[x][0]++;
      if(scores[x][0] < 5) {
        scores[x][1] += cur;
      } else if(scores[x][0] == 5) {
        scores[x][2] = cur;
      }
      cur++;
    }
  }

  int min = 10000, win;
  for(int i = 1; i <= teamCount; i++) {
    if(scores[i][1] == 0) {
      continue;
    }
    if(scores[i][1] < min || (scores[i][1] == min && scores[i][2] < scores[win][2])) {
      min = scores[i][1];
      win = i;
    }
  }
  return win;
}