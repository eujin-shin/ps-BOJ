#include <iostream>
using namespace std;

int main() {
  long long n, f = 1, x = 2;
  cin>>n;
  if(n == 0) {
    n = -1;
  }

  while(f * x <= n) {
    f = f * x++;
  }

  while(n > 0 && x > 0) {
    if(f <= n) {
      n -= f;
    }
    x--;
    if(x > 0) {
      f = f / x;
    }
  }

  if(n == 0) {
    cout<<"YES\n";
  } else {
    cout<<"NO\n";
  }
  return 0;
}