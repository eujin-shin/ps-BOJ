#include <iostream>
using namespace std;

void solve(int n) {
  bool flag = false;
  for(int i = 0, x = 1; x <= n; i++, x<<=1) {
    if(!(x & n)) {
      continue;
    } else if(flag) {
      cout<<' '<<i;
    } else {
      flag = true;
      cout<<i;
    }
  }
  cout<<'\n';
  return;
}

int main() {
  int t, n;
  cin>>t;
  while(t--) {
    cin>>n;
    solve(n);
  }
  return 0;
}