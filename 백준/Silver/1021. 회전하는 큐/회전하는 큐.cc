#include <iostream>
using namespace std;

int n, deque[60] = {0, }, temp[60] = {0, };

int find(int x) {
  int ans = 0;  
  for(int i = 1; i <= n; i++) {
    if(deque[i] == x) {
      ans = i;
      break;
    }
  }
  return ans;
}

void popLeft(int k) {
  for(int i = 1; i < n; i++) {
    temp[i] = (i + k <= n ? deque[i + k] : deque[i + k - n]);
  }
  for(int i = 1; i < n; i++) {
    deque[i] = temp[i];
  }
  return;
}

void popRight(int k) {
  for(int i = 1; i <= n; i++) {
    temp[i] = (i - k >= 1 ? deque[i - k] : deque[n - k + i]);
  }
  for(int i = 1; i < n; i++) {
    deque[i] = temp[i + 1];
  }
  return;
}

int main() {
  int m;
  cin>>n>>m;
  for(int i = 1; i <= n; i++) {
    deque[i] = i;
  }

  int x, left, right, sum = 0;
  for(int i = 0; i < m; i++) {
    cin>>x;
    left = find(x);
    right = n - left + 1;

    if(left - 1 < right) {
      sum += left - 1;
      popLeft(left);
    } else {
      sum += right;
      popRight(right);
    }
    n--;
  }
  cout<<sum<<'\n';
  return 0;
}