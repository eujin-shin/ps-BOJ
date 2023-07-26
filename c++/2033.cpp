#include <iostream>
using namespace std;

int main() {
  int n, k=10;
  cin>>n;
  while(k<n) {
    if(n%k>=k/2) n+=k;
    n-=n%k; k*=10;
  }
  cout<<n<<'\n';
  return 0;
}