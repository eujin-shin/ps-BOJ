#include <iostream>
using namespace std;

int len[3] = {1, 1, 1};

int main() {
  ios_base::sync_with_stdio(false);
  int n, prev, cur, max = 1;
  cin>>n>>prev;
  for(int i = 1; i < n; i++) {
    cin>>cur;

    if(cur == prev) {
      len[0]++;
      len[1]++;
      len[2]++;
    } else if(cur > prev) {
      if(max < len[0]) {
        max = len[0];
      }
      len[0] = 1;
      len[1] = 1;
      len[2]++;
    } else {
      if(max < len[2]) {
        max = len[2];
      }
      len[2] = 1;
      len[1] = 1;
      len[0]++;
    }
    prev = cur;
  }
  if(max < len[0]) {
    max = len[0];
  }
  if(max < len[2]) {
    max = len[2];
  }
  cout<<max<<'\n';
  return 0;
}