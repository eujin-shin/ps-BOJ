#include <iostream>
using namespace std;

int i(int y, int z) {
  if(z==0) return 0;
  if(z%2!=0) return i(2*y, (z-1)/2)+y;
  else return i(2*y, z/2);
}

int main() {
  int y, z;
  cin>>y>>z;
  cout<<i(y, z)<<'\n';
}