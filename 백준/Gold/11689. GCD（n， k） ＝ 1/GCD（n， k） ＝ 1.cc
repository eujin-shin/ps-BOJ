#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector <long long> v[20];

long long update(int k, long long x, long long n) {
  long long sum = n / x - 1, value;
  for(int i = k; i > 1; i--) {
    for(int j = v[i - 1].size() - 1; j >= 0; j--) {
      value = v[i - 1][j] * x;
      if(value > n) {
        continue;
      }
      v[i].push_back(value);
      if(i % 2 == 0) {
        sum -= n / value - 1;
      } else {
        sum += n / value - 1;
      }
    }
  }
  v[1].push_back(x);
  return sum;
}

int main() {
  long long n;
  cin>>n;
  long long cnt = (n > 1) ? 1 : 0, temp = n;
  int k = 0;
  for(long long x = 2; x <= temp && x <= sqrt(n); x++) {
    if(temp % x != 0) continue;
    cnt += update(++k, x, n);
    while(temp % x == 0) temp /= x;
  }
  if(temp > 1) {
    cnt += update(++k, temp, n);
  }
  cout<<n - cnt<<'\n';
  return 0;
}