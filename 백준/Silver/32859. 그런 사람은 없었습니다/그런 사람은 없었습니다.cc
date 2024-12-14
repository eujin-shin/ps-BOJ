#include <iostream>
using namespace std;

int submits[2001] = {0, }, dues[2001] = {0, };

int main() {
  int n, m, s;
  cin>>n>>m>>s;
  for(int i = 1; i <= n; i++) {
    submits[i] = n;
    dues[i] = n;
  }
  int x, t, submitCount = 0;
  for(int i = 0; i < m; i++) {
    cin>>x>>t;
    if(t == 0) {
      submits[x] = submitCount++;
    } else {
      dues[x] = submitCount + s;
    }
  }
  bool noAnswer = true;
  for(int i = 1; i <= n; i++) {
    if(submits[i] >= dues[i] && dues[i] <= submitCount) {
      noAnswer = false;
      cout<<i<<'\n';
    }
  }
  if(noAnswer) {
    cout<<"-1\n";
  }
  return 0;
}