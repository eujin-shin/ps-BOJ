#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, x, y;
  cin>>t;
  for(int i=1; i<=t; i++) {
    cin>>x>>y;
    cout<<"Case "<<i<<": "<<x+y<<'\n';
  }
  return 0;
}