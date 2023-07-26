#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  queue <int> q;
  int input[102][102] = {0, }, output[102][102] = {0, };
  int n, x, cur;
  cin>>n;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cin>>x;
      if(x) {
        input[i][0] = input[i][0] + 1;
        input[i][input[i][0]] = j;
      }
    }
  }
  for(int i=1; i<=n; i++) {
    q.push(i);
    while(!q.empty()) {
      cur = q.front(); q.pop();
      for(int j=1; j<=input[cur][0]; j++) {
        if(output[i][input[cur][j]]==0) {
          q.push(input[cur][j]);
          output[i][input[cur][j]] = 1;
        }
      }
    }
  }
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      cout<<output[i][j];
      if(j!=n) {
        cout<<' ';
      }
    }
    cout<<'\n';
  }
  return 0;
}