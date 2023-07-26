#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin>>n;
  for(int i=0; i<9; i++) {
    cin>>x; n-=x;
  }
  cout<<n<<'\n';
  return 0;
}