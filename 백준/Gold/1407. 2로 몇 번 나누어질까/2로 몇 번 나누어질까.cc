#include <iostream>
using namespace std;

int main() {
  long long a, b;
  cin>>a>>b;

  long long x = 1;
  while(x * 2 <= b) {
    x *= 2;
  }
  
  long long count = 0, sum = 0, cur;
  while(x > 0) {
    cur = b / x - a / x + (a % x == 0) - count;
    count += cur;
    sum += x * cur;
    x /= 2;
  } 
  cout<<sum<<'\n';
  return 0;
}