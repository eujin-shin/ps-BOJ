#include <iostream>
#include <map>
using namespace std;

int main() {
  map <int, int> count;
  int n, m, k, x;
  cin>>n>>m;

  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin>>k;
    for(int j = 0; j < k; j++) {
      cin>>x;
      ans += ++count[x] == m ? 1 : 0;
    }
  }
  cout<<ans<<'\n';
  return 0;
}