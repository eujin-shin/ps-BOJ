#include <iostream>
#include <string>
using namespace std;

int main() {
  int n, p, c, max=0;
  string name, ans;
  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>p; max=0;
    for(int j=0; j<p; j++) {
      cin>>c>>name;
      if(c>max) {
        max=c; ans=name;
      }
    }
    cout<<ans<<'\n';
  }
  return 0;
}