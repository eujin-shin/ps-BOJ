#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin>>s;
  int cur = 1, n = 1, k = 1, digit, target;
  for(int i = 0; i < s.length(); i++) {
    target = s[i] - '0';
    digit = -1;
    while(digit != target) {
      digit = cur / k % 10;
      if(k == 1) {
        cur++;
        if(cur >= n * 10) {
          n *= 10;
        }
        k = n;
      } else {
        k /= 10;
      }
    }
  }
  cout<<(n == k ? cur - 1 : cur)<<'\n';
  return 0;
}