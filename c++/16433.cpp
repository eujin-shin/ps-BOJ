#include <iostream>
using namespace std;

int main() {
  int n, r, c;
  cin>>n>>r>>c;
  r%=2; c%=2;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if((i%2==r && j%2==c) || (i%2!=r && j%2!=c)) cout<<'v';
      else cout<<'.';
    }
    cout<<'\n';
  }
  return 0;
}