#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long> v;

long long getDistance(long long x);

int main() {
  int n;
  long long x;
  cin>>n;
  for(int i = 0; i < n; i++) {
    cin>>x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  int a = 0, b = n - 1, c;
  int ans[3] = {0, };
  long long min = -1, dist, value;
  for(int i = 0; i < n - 2; i++) {
    for(int j = i + 2; j < n; j++) {
      a = i; b = j;
      value = v[i] + v[j];
      while(a < b - 1) {
        c = (a + b) / 2;
        dist = getDistance(value + v[c]);
        if(min < 0 || dist < min) {
          min = dist;
          ans[0] = v[i];
          ans[1] = v[c];
          ans[2] = v[j];
        }
        if(value + v[c] < 0) {
          a = c;
        } else if(value + v[c] > 0) {
          b = c;
        } else {
          break;
        }
      }
    }
    if(min == 0) {
      break;
    }
  }
  cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';
  return 0;
}

long long getDistance(long long x) {
  if(x >= 0) {
    return x;
  }
  return -x;
}