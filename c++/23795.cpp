#include <iostream>
using namespace std;

int main() {
  int sum=0, x;
  cin>>x;
  while(x>0) {
    sum+=x; cin>>x;
  }
  cout<<sum<<'\n';
  return 0;
}