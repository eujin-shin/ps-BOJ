#include <iostream>
using namespace std;

int main() {
  double x, y;
  int z, tmp, n=-1;
  cin>>x>>y;
  z=y/x*100;
  for(int i=1; z<99; i++) {
    tmp=(y+i)*100/(x+i);
    if(tmp<=z) continue;
    n=i; break;
  }
  cout<<n<<'\n';
  return 0;
}