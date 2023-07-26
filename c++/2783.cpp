#include <iostream>
using namespace std;

int main() {
  int n;
  double min, x, y;
  cin>>x>>y>>n;
  min = x / y * 1000;
  for(int i=0; i<n; i++) {
    cin>>x>>y;
    if(x/y*1000<min) min=x/y*1000;
  }
  cout<<min<<'\n';
  return 0;
}