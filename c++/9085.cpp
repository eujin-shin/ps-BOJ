#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int t, n, sum, tmp;
  cin>>t;
  while(t--) {
    cin>>n; sum=0;
    for(int i=0; i<n; i++) {
      cin>>tmp; sum+=tmp;
    }
    cout<<sum<<'\n';
  }
  return 0;
}