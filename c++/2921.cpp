#include <iostream>
using namespace std;

int main() {
  int n, k, sum=0;
  cin>>n;
  k = 2*(n+1) - n;
  for(int i=1; i<=n; i++) sum+=k*i;
  cout<<sum<<'\n';
  return 0;
}