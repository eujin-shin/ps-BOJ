#include <iostream>
using namespace std;

int main() {
  long long n, x=1;
  cin>>n;
  while(x*x<=n) x++;
  cout<<x-1<<'\n';
  return 0;
}