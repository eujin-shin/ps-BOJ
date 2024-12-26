#include <iostream>
using namespace std;

int getGcd(int x, int y) {
  int a = x, b = y;
  if(y > x) {
    a = y;
    b = x;
  }
  if(b == 0) {
    return a;
  }
  return getGcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int arr[100] = {0, };
  int t, n;
  long long sum;
  cin>>t;
  while(t--) {
    cin>>n;
    for(int i = 0; i < n; i++) {
      cin>>arr[i];
    }
    sum = 0;
    for(int i = 0; i < n - 1; i++) {
      for(int j = i + 1; j < n; j++) {
        sum += getGcd(arr[i], arr[j]);
      }
    }
    cout<<sum<<'\n';
  }
  return 0;
}