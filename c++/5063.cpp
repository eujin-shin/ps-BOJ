#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, r, e, c;
  cin>>n;
  while(n--) {
    cin>>r>>e>>c;
    if(e-c>r) cout<<"advertise\n";
    else if(e-c<r) cout<<"do not advertise\n";
    else cout<<"does not matter\n";
  }
  return 0;
}