#include <iostream>
using namespace std;

int main() {
  int max=0, win, x, s;
  for(int i=1; i<=5; i++) {
    s=0;
    for(int j=0; j<4; j++) {
      cin>>x; s+=x;
    }
    if(max>s) continue;
    max=s; win=i;
  }
  cout<<win<<' '<<max<<'\n';
  return 0;
}