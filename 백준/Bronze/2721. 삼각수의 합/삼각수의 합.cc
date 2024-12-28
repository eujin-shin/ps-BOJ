#include <iostream>
using namespace std;

long long triangular[301] = {0, 1, }, weighted[301] = {0, };

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, max = 0, n;
  cin>>t;
  while(t--) {
    cin>>n;
    while(max <= n) {
      triangular[max + 1] = triangular[max] + max + 1;
      weighted[max] = weighted[max - 1] + triangular[max + 1] * max;
      max++;
    }
    cout<<weighted[n]<<'\n';
  }
  return 0;
}