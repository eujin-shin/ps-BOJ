#include <iostream>
#include <cmath>
using namespace std;

int main() {
  long long n;
  long double q;
  cin>>n;
  cout<<n<<'\n';
  q = sqrt(n);
  cout<<q<<'\n';
  q = ceil(q);
  cout<<q<<'\n';
  return 0;
}