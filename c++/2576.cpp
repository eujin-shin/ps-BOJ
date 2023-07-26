#include <iostream>
using namespace std;

int main() {
  int x, sum=0, min=100;
  for(int i=0; i<7; i++) {
    cin>>x;
    if(x%2==0) continue;
    sum+=x;
    if(min>x) min=x;
  }
  if(sum==0) {
    cout<<"-1\n";
    return 0;
  }
  cout<<sum<<'\n'<<min<<'\n';
  return 0;
}