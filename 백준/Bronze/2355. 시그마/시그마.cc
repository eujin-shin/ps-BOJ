#include <iostream>
using namespace std;

int main() {
  long long a, b, temp, x, n;
  cin>>a>>b;
  if(a > b) {
    temp = b;
    b = a;
    a = temp;
  }
  x = a + b;
  n = b - a + 1;
  if(n % 2 == 0) {
    n /= 2;
  } else {
    x /= 2;
  }
  cout<<n * x<<'\n';
  return 0;
}