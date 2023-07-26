#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, m, a, b;
  cin>>t;
  for(int i=0; i<t; i++) {
    cin>>n>>m;
    for(int j=0; j<m; j++) {
      cin>>a>>b;
    }
    cout<<n-1<<'\n';
  }
  return 0;
}