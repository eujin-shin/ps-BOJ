#include <iostream>
#include <vector>
using namespace std;

vector <int> lions;

int main() {
  int n, k, x;
  cin>>n>>k;
  for(int i = 1; i <= n; i++) {
    cin>>x;
    if(x == 1) {
      lions.push_back(i);
    }
  }

  int ans = -1, len;
  for(int i = 0; i + k - 1 < lions.size(); i++) {
    len = lions[i + k - 1] - lions[i] + 1;
    ans = ans < 0 || len < ans ? len : ans;
  } 
  cout<<ans<<'\n';
  return 0;
}