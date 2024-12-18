#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  int n, k, left, right;
  cin>>n>>k>>left;
  right = left;

  int count = 0, key;
  for(int i = 1; i < n; i++) {
    cin>>key;
    if(key <= right - k || key >= left + k) {
      count++;
      left = right = key;
    } else if(key < left) {
      left = key;
    } else if(key > right) {
      right = key;
    }
  }

  cout<<count<<'\n';
  return 0;
}