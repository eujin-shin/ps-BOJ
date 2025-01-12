#include <iostream>
using namespace std;

int main() {
  int n;
  cin>>n;

  bool hasNumber = false;
  for(int i = 1; i <= 9 && !hasNumber; i++) {
    if(n % i == 0 && n / i <= 9 && n / i > 0) {
      hasNumber = true;
    }
  }

  cout<<(hasNumber ? 1 : 0)<<'\n';
  return 0;
}