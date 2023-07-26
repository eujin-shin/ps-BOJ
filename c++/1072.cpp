#include <iostream>
#include <math.h>
using namespace std;

int main() {
  double x, y, z;
  int n=-1;
  cin>>x>>y;
  z=ceil((x-y)/x*100)-1;
  if(z>0) n=ceil((x-y)/z*100)-x;
  cout<<n<<'\n';
  return 0;
}